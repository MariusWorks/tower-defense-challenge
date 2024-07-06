// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerOffensive.h"


ATowerOffensive::ATowerOffensive()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn"));
	ProjectileSpawn->SetupAttachment(WeaponPropMesh);
}

void ATowerOffensive::BeginPlay()
{
	TowerMaxUpgradeIndex = TowerOffensiveStruct.TowerData.Num() - 1;
	
	Super::BeginPlay();
}

void ATowerOffensive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

