// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerPlot.h"

ATowerPlot::ATowerPlot()
{
	PrimaryActorTick.bCanEverTick = false;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	SetRootComponent(TileMesh);
	TileMesh->SetCollisionProfileName("NoCollision", false);

	Box1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box 1"));
	Box1->SetupAttachment(TileMesh);
	Box1->SetCollisionProfileName("TowerPlot", false);
	Box1->SetBoxExtent(FVector(65.f, 65.f, 10.f), false);
	Box1->SetRelativeLocation(FVector(65.f, -65.f, 52.f));
	BoxMap.Add(Box1, false);
	
	Box2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box 2"));
	Box2->SetupAttachment(TileMesh);
	Box2->SetCollisionProfileName("TowerPlot", false);
	Box2->SetBoxExtent(FVector(65.f, 65.f, 10.f), false);
	Box2->SetRelativeLocation(FVector(65.f, 65.f, 52.f));
	BoxMap.Add(Box2, false);
	
	Box3 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box 3"));
	Box3->SetupAttachment(TileMesh);
	Box3->SetCollisionProfileName("TowerPlot", false);
	Box3->SetBoxExtent(FVector(65.f, 65.f, 10.f), false);
	Box3->SetRelativeLocation(FVector(-65.f, 65.f, 52.f));
	BoxMap.Add(Box3, false);
	
	Box4 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box 4"));
	Box4->SetupAttachment(TileMesh);
	Box4->SetCollisionProfileName("TowerPlot", false);
	Box4->SetBoxExtent(FVector(65.f, 65.f, 10.f), false);
	Box4->SetRelativeLocation(FVector(-65.f, -65.f, 52.f));
	BoxMap.Add(Box4, false);
}

void ATowerPlot::BeginPlay()
{
	Super::BeginPlay();
}

bool ATowerPlot::UpdateTowerPlot(UPrimitiveComponent* InBoxComponent, bool bInPlotTaken)
{
	if (BoxMap.Contains(InBoxComponent))
	{
		BoxMap.Add(InBoxComponent, bInPlotTaken);
		return true;
	}
	return false;
}

bool ATowerPlot::IsPlotTaken(UPrimitiveComponent* InBoxComponent)
{
	if (BoxMap.Contains(InBoxComponent))
	{
		return *BoxMap.Find(InBoxComponent);
	}
	return false;
}
