// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerUtility.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.generated.h"

UCLASS()
class TDC_API AProjectileBase : public AActor
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile", meta = (AllowPrivateAccess))
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile", meta = (AllowPrivateAccess))
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile", meta = (AllowPrivateAccess))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY()
	AActor* Target;

	UPROPERTY()
	float InitialDistanceToTarget;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Projectile", meta = (ExposeOnSpawn))
	int InTowerUpgradeIndex;

	UPROPERTY(BlueprintReadOnly, Category = "Projectile", meta = (ExposeOnSpawn))
	FTowerStruct InTowerStruct;
	
public:

	AProjectileBase();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	/* Functions */

protected:

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
public:

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void Fire(const FVector& InVelocity, AActor* InTarget);

	UFUNCTION()
	float GetDistanceToTarget() const;
};
