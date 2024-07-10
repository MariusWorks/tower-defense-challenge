// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerInterface.h"
#include "TowerUtility.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "TowerBase.generated.h"

class UTowerSubsystem;
class UGameSubsystem;

UCLASS(Abstract, NotBlueprintable)
class TDC_API ATowerBase : public AActor, public ITowerInterface
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdateStats);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UStaticMeshComponent* TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UStaticMeshComponent* WeaponBaseMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	UDecalComponent* DecalRange;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USphereComponent* SphereRadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	UStaticMeshComponent* WeaponPropMesh;

	UPROPERTY(BlueprintReadOnly, Category = "Tower Stats", meta = (ExposeOnSpawn))
	FTowerStruct TowerStruct;

	UPROPERTY(BlueprintReadWrite, Category = "Tower Stats")
	FTowerStats TowerStats;

private:

	UPROPERTY()
	UGameSubsystem* GameSubsystem;

	UPROPERTY()
	UTowerSubsystem* TowerSubsystem;
	
	UPROPERTY()
	bool bTowerActive = false;

	UPROPERTY()
	int UpgradeIndex = 0;

	UPROPERTY()
	int MaxUpgradeIndex = 0;

	UPROPERTY()
	bool bHasTowerBeenUsed = false;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUpdateStats OnUpdateStats;

	
	/* Engine Defaults */
public:

	ATowerBase();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	/* ITowerInterface Implementation */

	UFUNCTION()
	virtual void OnTowerPlaced_Implementation() override;

	UFUNCTION()
	virtual bool OnTowerUpgrade_Implementation() override;

	UFUNCTION()
	virtual bool OnTowerSell_Implementation() override;

	UFUNCTION()
	virtual bool OnTowerMove_Implementation() override;

	UFUNCTION()
	virtual void OnTowerSelected_Implementation() override;

	UFUNCTION()
	virtual void OnTowerDeselected_Implementation() override;

	UFUNCTION()
	virtual void OnTowerDamageDealt_Implementation(float InDamageDealt) override;

	UFUNCTION()
	virtual void OnTowerKill_Implementation() override;

	UFUNCTION()
	void OnStatsUpdate();

	/*  */
	
	// Setters
	UFUNCTION(BlueprintCallable)
	void SetTowerActive(const bool bInTowerActive) {bTowerActive = bInTowerActive;}
	
	UFUNCTION(BlueprintCallable)
	void SetUpgradeIndex(const int InUpgradeIndex) {UpgradeIndex = InUpgradeIndex;}
	
	UFUNCTION(BlueprintCallable)
	void SetMaxUpgradeIndex(const int InMaxUpgradeIndex) {MaxUpgradeIndex = InMaxUpgradeIndex;}

	// Getters
	UFUNCTION(BlueprintPure)
	bool GetTowerActive() const {return bTowerActive;}

	UFUNCTION(BlueprintPure)
	int GetTowerUpgradeIndex() const {return UpgradeIndex;}

	UFUNCTION(BlueprintPure)
	int GetTowerMaxUpgradeIndex() const {return MaxUpgradeIndex;}

	UFUNCTION(BlueprintPure, Category = "Tower|Stats")
	float GetTowerRange() const {return TowerStruct.TowerData[UpgradeIndex].Range;}

	UFUNCTION(BlueprintPure, Category = "Tower|Stats")
	int GetTowerCost() const {return TowerStruct.TowerData[UpgradeIndex].Cost;}

	UFUNCTION(BlueprintPure, Category = "Tower|Stats")
	float GetTowerCooldown() const {return TowerStruct.TowerData[UpgradeIndex].Cooldown;}

	// Helpers
	UFUNCTION(BlueprintPure)
	int GetTowerAccumulatedCost();

	UFUNCTION(BlueprintPure)
	int GetTowerRefundPrice();

	UFUNCTION(BlueprintPure)
	int GetTowerMovePrice();

	UFUNCTION(BlueprintCallable)
	void UpdateRadius();

	UFUNCTION(BlueprintPure)
	bool GetHasTowerBeenUsed() {return bHasTowerBeenUsed;}

private:

	UFUNCTION()
	void SetTowerHasBeenUsed();
};
