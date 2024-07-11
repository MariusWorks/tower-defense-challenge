// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"

#include "TowerSubsystem.h"
#include "Components/DecalComponent.h"
#include "Tdc/Game/GameSubsystem.h"


ATowerBase::ATowerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(SceneComponent);

	TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Mesh"));
	TowerMesh->SetupAttachment(RootComponent);
	TowerMesh->SetWorldScale3D(FVector(0.4));
	TowerMesh->SetCollisionProfileName("Tower", false);

	WeaponBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Base Mesh"));
	WeaponBaseMesh->SetupAttachment(TowerMesh);
	WeaponBaseMesh->SetRelativeLocation(FVector(0.f, 0.f, 208.f));
	WeaponBaseMesh->SetCollisionProfileName("NoCollision", false);

	WeaponPropMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Prop Mesh"));
	WeaponPropMesh->SetupAttachment(WeaponBaseMesh);
	WeaponPropMesh->SetCollisionProfileName("NoCollision", false);

	SphereRadius = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Radius"));
	SphereRadius->SetupAttachment(RootComponent);
	SphereRadius->SetSphereRadius(100.f);
	SphereRadius->SetCollisionProfileName("TowerRadius", false);

	DecalRange = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Range"));
	DecalRange->SetupAttachment(RootComponent);
	DecalRange->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	DecalRange->DecalSize = FVector(100.f);
	DecalRange->SetHiddenInGame(true);
}


void ATowerBase::BeginPlay()
{
	Super::BeginPlay();

	TowerStats.MaxUpgradeIndex = TowerStruct.TowerData.Num() - 1;

	DefaultMaterials = TowerMesh->GetMaterials();

	UGameSubsystem* GetGameSubsystem = GetGameInstance()->GetSubsystem<UGameSubsystem>();
	if (GetGameSubsystem)
	{
		GameSubsystem = GetGameSubsystem;

		TowerStats.bHasTowerBeenUsed = GameSubsystem->GetIsWaveInProgress();

		if (!TowerStats.bHasTowerBeenUsed)
		{
			GameSubsystem->OnPlayerStartWave.AddDynamic(this, &ATowerBase::SetTowerHasBeenUsed);
		}
	}

	UTowerSubsystem* GetTowerSubsystem = GetGameInstance()->GetSubsystem<UTowerSubsystem>();
	if (GetTowerSubsystem)
	{
		TowerSubsystem = GetTowerSubsystem;
	}

	UpdateRadius();
}

void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ATowerBase::OnTowerUpgrade_Implementation()
{
	if (TowerStats.UpgradeIndex + 1 <= TowerStruct.TowerData.Num() - 1)
	{
		int TowerCost = TowerStruct.TowerData[TowerStats.UpgradeIndex + 1].Cost;
		if (GameSubsystem->SubtractPlayerGold(TowerCost))
		{
			TowerStats.UpgradeIndex++;
			
			if (TowerStruct.TowerData[TowerStats.UpgradeIndex].NextTowerTier)
			{
				
				HandleTowerNextTier();
				return true;
			}
			
			UpdateRadius();
			TowerSubsystem->OnTowerSelected.Broadcast(this);
			return true;
		}
	}
	return false;
}

bool ATowerBase::OnTowerSell_Implementation()
{
	if (UTowerUtility::TraceAndUpdatePlot(this, false))
	{
		if (GameSubsystem)
		{
			const int TowerCost = GetTowerAccumulatedCost();
			if (TowerStats.bHasTowerBeenUsed)
			{
				GameSubsystem->AddPlayerGold(TowerCost / 0.5f);
			}
			else
			{
				GameSubsystem->AddPlayerGold(TowerCost);
			}
			
			this->Destroy();
			return true;
		}
	}
	return false;
}

bool ATowerBase::OnTowerMove_Implementation()
{
	if (UTowerUtility::TraceAndUpdatePlot(this, false))
	{
		const int MoveCost = GetTowerAccumulatedCost();
		if (TowerStats.bHasTowerBeenUsed)
		{
			if (GameSubsystem->SubtractPlayerGold(MoveCost * 0.25))
			{
				SetTowerActive(false);
				return true;
			}
			UTowerUtility::TraceAndUpdatePlot(this, true);
		}
		else
		{
			SetTowerActive(false);
			return true;
		}
	}
	return false;
}

void ATowerBase::OnTowerPlaced_Implementation()
{
	SetTowerActive(true);
}

void ATowerBase::OnTowerSelected_Implementation()
{
	DecalRange->SetHiddenInGame(false);
	OnUpdateStats.AddDynamic(this, &ATowerBase::OnStatsUpdate);
	OnStatsUpdate();
}

void ATowerBase::OnTowerDeselected_Implementation()
{
	DecalRange->SetHiddenInGame(true);
	OnUpdateStats.Clear();
}

void ATowerBase::OnTowerDamageDealt_Implementation(float InDamageDealt)
{
	TowerStats.DamageDealt += InDamageDealt;
	OnUpdateStats.Broadcast();
}

void ATowerBase::OnTowerKill_Implementation()
{
	TowerStats.Kills++;
	OnUpdateStats.Broadcast();
}

void ATowerBase::OnSetPlacementValid_Implementation()
{
	if (!DefaultMaterials[0])
	{
		UE_LOG(LogActor, Warning, TEXT("%s | Something went wrong when assigning default materials back to actor"), *this->GetName());
		return;
	}
	
	if (TowerMesh->GetMaterial(0) != DefaultMaterials[0])
	{
		WeaponBaseMesh->SetHiddenInGame(false);
		WeaponPropMesh->SetHiddenInGame(false);
		
		for (int i = 0; i < TowerMesh->GetNumMaterials(); i++)
		{
			TowerMesh->SetMaterial(i, DefaultMaterials[i]);
		}
	}
}

void ATowerBase::OnSetPlacementInvalid_Implementation()
{
	if (!InvalidMaterial)
	{
		UE_LOG(LogActor, Warning, TEXT("%s | Invalid Material is not set for Tower Actor"), *this->GetName());
		return;
	}

	if (TowerMesh->GetMaterial(0) != InvalidMaterial)
	{
		WeaponBaseMesh->SetHiddenInGame(true);
		WeaponPropMesh->SetHiddenInGame(true);
		
		for (int i = 0; i < TowerMesh->GetNumMaterials(); i++)
		{
			TowerMesh->SetMaterial(i, InvalidMaterial);
		}
	}
}

void ATowerBase::OnStatsUpdate()
{
	TowerSubsystem->OnTowerSelected.Broadcast(this);
}

void ATowerBase::HandleTowerNextTier()
{
	const FTransform SpawnTransform = GetActorTransform();
	ATowerBase* NewTower = GetWorld()->SpawnActorDeferred<ATowerBase>(TowerStruct.TowerData[TowerStats.UpgradeIndex].NextTowerTier, SpawnTransform, GetOwner(), GetInstigator());
	if (NewTower)
	{
		NewTower->SetTowerStruct(TowerStruct);
		NewTower->SetTowerStats(TowerStats);
		NewTower->FinishSpawning(SpawnTransform, false);
		Execute_OnTowerPlaced(NewTower);
		Execute_OnTowerSelected(NewTower);
		this->Destroy();
	}
}

int ATowerBase::GetTowerAccumulatedCost()
{
	int AccumulatedCost = 0;

	for (int i = 0; i <= TowerStats.UpgradeIndex; i++)
	{
		AccumulatedCost += TowerStruct.TowerData[i].Cost;
	}

	return AccumulatedCost;
}

int ATowerBase::GetTowerRefundPrice()
{
	const int TowerCost = GetTowerAccumulatedCost();
	if (TowerStats.bHasTowerBeenUsed)
	{
		return TowerCost * 0.5f;
	}
	
	return TowerCost;
}

int ATowerBase::GetTowerMovePrice()
{
	const int TowerCost = GetTowerAccumulatedCost();
	if (TowerStats.bHasTowerBeenUsed)
	{
		return TowerCost * 0.25f;
	}
	return 0;
}

void ATowerBase::UpdateRadius()
{
	SphereRadius->SetSphereRadius(TowerStruct.TowerData[TowerStats.UpgradeIndex].Range);
	DecalRange->SetWorldScale3D(FVector(TowerStruct.TowerData[TowerStats.UpgradeIndex].Range / 100.f));
}

void ATowerBase::SetTowerHasBeenUsed()
{
	TowerStats.bHasTowerBeenUsed = true;
	GameSubsystem->OnPlayerStartWave.RemoveDynamic(this, &ATowerBase::SetTowerHasBeenUsed);
}

