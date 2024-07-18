// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "TowerOffensive.generated.h"

class AEnemyBase;
class AProjectileBase;

UCLASS(Abstract, Blueprintable)
class TDC_API ATowerOffensive : public ATowerBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USceneComponent* ProjectileSpawn;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Tower | Offensive")
	AProjectileBase* SpawnedProjectile;

	UPROPERTY(BlueprintReadOnly, Category = "Tower")
	TArray<AEnemyBase*> Enemies;

	UPROPERTY(BlueprintReadWrite, Category = "Tower|Targeting")
	ETargetingTypes TargetPriority;

public:

	ATowerOffensive();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:
	
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	/* ITowerInterface Implementation */

	virtual bool OnTowerSell_Implementation() override;

	UFUNCTION()
	virtual void OnNextTargeting_Implementation(ETargetingTypes& OutTargetingType) override;

	UFUNCTION()
	virtual void OnPreviousTargeting_Implementation(ETargetingTypes& OutTargetingType) override;

	UFUNCTION()
	virtual void GetTowerTargeting_Implementation(ETargetingTypes& OutTargetingType) override;

	UFUNCTION()
	virtual void OnTowerApplyBuff_Implementation(FPassiveEffect InPassiveEffect) override;

	UFUNCTION()
	virtual void OnTowerRemoveBuff_Implementation(FPassiveEffect InPassiveEffect) override;

	/* End of ITower Interface Implementation */

	virtual void HandleTowerNextTier() override;
	
};
