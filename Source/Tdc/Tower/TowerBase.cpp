// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"

#include "Components/DecalComponent.h"


ATowerBase::ATowerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(SceneComponent);

	TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Mesh"));
	TowerMesh->SetupAttachment(RootComponent);
	TowerMesh->SetWorldScale3D(FVector(0.4));

	WeaponBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Base Mesh"));
	WeaponBaseMesh->SetupAttachment(TowerMesh);
	WeaponBaseMesh->SetRelativeLocation(FVector(0.f, 0.f, 208.f));

	WeaponPropMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Prop Mesh"));
	WeaponPropMesh->SetupAttachment(WeaponBaseMesh);

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
}


void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

