// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tdc/Enemy/EnemyUtility.h"
#include "GameSubsystem.generated.h"

class ATowerBase;
/**
 * 
 */
UCLASS()
class TDC_API UGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	// Wave Communication
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerStartWave);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveStarted, FWave, InWaveInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWaveFinished);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextWaveReady);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDeath, AEnemyBase*, InEnemyDeath);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartWaveCountdownTimer, float, InTime);
	
	// Stats Communication
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivesUpdated, int, InLives);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoldUpdated, int, InGold);

	// Tower Communication
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerUpgradeRequest, ATowerBase*, InTowerToUpgrade);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerSellRequest, ATowerBase*, InTowerToSell);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerMoveRequest, ATowerBase*, InTowerToMove);

public:

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnPlayerStartWave OnPlayerStartWave;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnWaveStarted OnWaveStarted;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnWaveFinished OnWaveFinished;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnNextWaveReady OnNextWaveReady;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnEnemyDeath OnEnemyDeath;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnStartWaveCountdownTimer OnStartWaveCountdownTimer;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnLivesUpdated OnLivesUpdated;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnGoldUpdated OnGoldUpdated;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerUpgradeRequest OnTowerUpgradeRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerSellRequest OnTowerSellRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerMoveRequest OnTowerMoveRequest;
	
};
