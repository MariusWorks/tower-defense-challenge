// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerUtility.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "TowerBase.generated.h"

UCLASS(Abstract)
class TDC_API ATowerBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UStaticMeshComponent* TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UStaticMeshComponent* WeaponBaseMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USphereComponent* SphereRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UDecalComponent* DecalRange;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdateStats);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	UStaticMeshComponent* WeaponPropMesh;
	
	UPROPERTY()
	bool bTowerActive = false;

	UPROPERTY()
	int TowerUpgradeIndex = 0;

	UPROPERTY()
	int TowerMaxUpgradeIndex = 0;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUpdateStats OnUpdateStats;

public:
	// Sets default values for this actor's properties
	ATowerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Setters
	UFUNCTION(BlueprintCallable)
	void SetTowerActive(const bool bInTowerActive) {bTowerActive = bInTowerActive;}
	
	UFUNCTION(BlueprintCallable)
	void SetTowerUpgradeIndex(const int InTowerUpgradeIndex) {TowerUpgradeIndex = InTowerUpgradeIndex;}
	
	UFUNCTION(BlueprintCallable)
	void SetTowerMaxUpgradeIndex(const int InTowerMaxUpgradeIndex) {TowerMaxUpgradeIndex = InTowerMaxUpgradeIndex;}

	// Getters
	UFUNCTION(BlueprintPure)
	bool GetTowerActive() const {return bTowerActive;}

	UFUNCTION(BlueprintPure)
	int GetTowerUpgradeIndex() const {return TowerUpgradeIndex;}

	UFUNCTION(BlueprintPure)
	int GetTowerMaxUpgradeIndex() const {return TowerMaxUpgradeIndex;}
};
