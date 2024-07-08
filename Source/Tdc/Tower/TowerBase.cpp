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

	MaxUpgradeIndex = TowerStruct.TowerData.Num() - 1;

	UGameSubsystem* GetGameSubsystem = GetGameInstance()->GetSubsystem<UGameSubsystem>();
	if (GetGameSubsystem)
	{
		GameSubsystem = GetGameSubsystem;
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
	if (UpgradeIndex + 1 <= TowerStruct.TowerData.Num() - 1)
	{
		int TowerCost = TowerStruct.TowerData[UpgradeIndex + 1].Cost;
		if (GameSubsystem->SubtractPlayerGold(TowerCost))
		{
			UpgradeIndex++;
			UpdateRadius();
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
			if (bHasTowerBeenUsed)
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
		if (bHasTowerBeenUsed)
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

void ATowerBase::OnStatsUpdate()
{
	TowerSubsystem->OnTowerSelected.Broadcast(this);
}

int ATowerBase::GetTowerAccumulatedCost()
{
	int AccumulatedCost = 0;

	for (int i = 0; i < UpgradeIndex; i++)
	{
		AccumulatedCost += TowerStruct.TowerData[i].Cost;
	}

	return AccumulatedCost;
}

void ATowerBase::UpdateRadius()
{
	SphereRadius->SetSphereRadius(TowerStruct.TowerData[UpgradeIndex].Range);
	DecalRange->SetWorldScale3D(FVector(TowerStruct.TowerData[UpgradeIndex].Range / 100.f));
}

