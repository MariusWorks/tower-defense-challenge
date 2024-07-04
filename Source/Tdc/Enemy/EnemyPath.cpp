// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPath.h"

AEnemyPath::AEnemyPath()
{
	PrimaryActorTick.bCanEverTick = false;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SetRootComponent(SplineComponent);
}

void AEnemyPath::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

