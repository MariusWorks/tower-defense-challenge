// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SetRootComponent(SphereComponent);
	SphereComponent->SetCollisionProfileName("Projectile", false);

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(SphereComponent);
	ProjectileMesh->SetCollisionProfileName("NoCollision", false);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
	ProjectileMovement->bRotationFollowsVelocity = true;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::OnComponentBeginOverlap);
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target)
	{
		const float Alpha = GetDistanceToTarget() / InitialDistanceToTarget;
		ProjectileMovement->HomingAccelerationMagnitude = UKismetMathLibrary::Lerp(50000.f, 0.f, Alpha);
	}
}

void AProjectileBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void AProjectileBase::Fire(const FVector& InVelocity, AActor* InTarget)
{
	if (!ProjectileMovement)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectileMovement is NULL!"))
		return;
	}
	ProjectileMovement->Velocity = InVelocity;

	if (InTarget)
	{
		// @RECALL Update to Actual Enemy target instead of center of actor
		Target = InTarget;
		ProjectileMovement->HomingTargetComponent = Target->GetRootComponent();
		ProjectileMovement->bIsHomingProjectile = true;
		ProjectileMovement->HomingAccelerationMagnitude = 500.f;
		InitialDistanceToTarget = GetDistanceToTarget();
		SetActorTickEnabled(true);
	}
	else
	{
		ProjectileMovement->bIsHomingProjectile = false;
	}
	ProjectileMovement->Activate(false);
	SetLifeSpan(3.f);
}

float AProjectileBase::GetDistanceToTarget() const
{
	return (GetActorLocation() - Target->GetActorLocation()).Length();
}

