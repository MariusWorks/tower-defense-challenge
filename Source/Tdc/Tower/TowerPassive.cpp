// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPassive.h"

ATowerPassive::ATowerPassive()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereRadius->OnComponentBeginOverlap.AddDynamic(this, &ATowerPassive::OnComponentBeginOverlap);
	SphereRadius->OnComponentEndOverlap.AddDynamic(this, &ATowerPassive::OnComponentEndOverlap);
}

void ATowerPassive::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(false);
}

void ATowerPassive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerPassive::OnTowerPlaced_Implementation()
{
	// For each apply buff
	
	Super::OnTowerPlaced_Implementation();
}

bool ATowerPassive::OnTowerSell_Implementation()
{
	// For each remove buff
	
	return Super::OnTowerSell_Implementation();
}

bool ATowerPassive::OnTowerMove_Implementation()
{
	// For each remove buff
	
	return Super::OnTowerMove_Implementation();
}

void ATowerPassive::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATowerBase* OverlappingTower = Cast<ATowerBase>(OtherActor);
	if (OverlappingTower)
	{
		Towers.AddUnique(OverlappingTower);
		// @RECALL Add buff??
	}
}

void ATowerPassive::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATowerBase* OverlappingTower = Cast<ATowerBase>(OtherActor);
	if (OverlappingTower && Towers.Contains(OverlappingTower))
	{
		Towers.Remove(OverlappingTower);
	}
}

