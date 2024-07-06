// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPassive.h"


// Sets default values
ATowerPassive::ATowerPassive()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATowerPassive::BeginPlay()
{
	TowerMaxUpgradeIndex = TowerPassiveStruct.TowerData.Num() - 1;
	
	Super::BeginPlay();
}

// Called every frame
void ATowerPassive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

