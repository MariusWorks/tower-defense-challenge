// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerOffensive.h"

#include "ProjectileBase.h"
#include "Tdc/Enemy/EnemyBase.h"

ATowerOffensive::ATowerOffensive()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn"));
	ProjectileSpawn->SetupAttachment(WeaponPropMesh);

	SphereRadius->OnComponentBeginOverlap.AddDynamic(this, &ATowerOffensive::OnComponentBeginOverlap);
	SphereRadius->OnComponentEndOverlap.AddDynamic(this, &ATowerOffensive::OnComponentEndOverlap);
}

void ATowerOffensive::BeginPlay()
{
	Super::BeginPlay();
}

void ATowerOffensive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerOffensive::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEnemyBase* OverlappingEnemy = Cast<AEnemyBase>(OtherActor);
	if (OverlappingEnemy)
	{
		Enemies.AddUnique(OverlappingEnemy);
	}
}

void ATowerOffensive::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AEnemyBase* OverlappingEnemy = Cast<AEnemyBase>(OtherActor);
	if (OverlappingEnemy && Enemies.Contains(OverlappingEnemy))
	{
		Enemies.Remove(OverlappingEnemy);
	}
}

bool ATowerOffensive::OnTowerSell_Implementation()
{
	if (SpawnedProjectile)
	{
		SpawnedProjectile->Destroy();
	}
	
	return Super::OnTowerSell_Implementation();
}

void ATowerOffensive::OnTowerApplyBuff_Implementation(FPassiveEffect InPassiveEffect)
{
	
}

void ATowerOffensive::OnTowerRemoveBuff_Implementation(FPassiveEffect InPassiveEffect)
{
	
}

