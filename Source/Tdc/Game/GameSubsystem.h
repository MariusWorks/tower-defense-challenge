// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tdc/Enemy/EnemyUtility.h"
#include "Tdc/Tower/TowerUtility.h"
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
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerOffensiveBuyRequest, FTowerOffensiveStruct, InOffensiveTower);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerPassiveBuyRequest, FTowerPassiveStruct, InPassiveTower);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerUpgradeRequest, AActor*, InTowerToUpgrade);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerSellRequest, AActor*, InTowerToSell);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerMoveRequest, AActor*, InTowerToMove);

public:

	// Wave Communication
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

	// Stats Communication
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnLivesUpdated OnLivesUpdated;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnGoldUpdated OnGoldUpdated;

	// Tower Communication
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerOffensiveBuyRequest OnTowerOffensiveBuyRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerPassiveBuyRequest OnTowerPassiveBuyRequest;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerUpgradeRequest OnTowerUpgradeRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerSellRequest OnTowerSellRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerMoveRequest OnTowerMoveRequest;
	
};
