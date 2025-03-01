// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tdc/Enemy/EnemyUtility.h"
#include "Tdc/Tower/TowerUtility.h"
#include "GameSubsystem.generated.h"

class ATdcGameState;
class ATdcPlayerState;
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
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveStarted, FCycle, InCycleInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWaveFinished);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextWaveReady);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveInProgress, bool, bInWaveInProgress);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDeath, AEnemyBase*, InEnemyDeath);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnemyReachedEnd);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartWaveCountdownTimer, float, InTime);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameLost);
	
	// Stats Communication
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivesUpdated, int, InLives);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoldUpdated, int, InGold);
	DECLARE_DYNAMIC_DELEGATE_RetVal(float, FGetPlayerGold);

	// Tower Communication
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerBuyRequest, FTowerStruct, InTowerStruct);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerUpgradeRequest, AActor*, InTowerToUpgrade);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerSellRequest, AActor*, InTowerToSell);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerMoveRequest, AActor*, InTowerToMove);

	UPROPERTY()
	ATdcPlayerState* PlayerState;

	UPROPERTY()
	ATdcGameState* GameState;

	UPROPERTY()
	bool bIsWaveInProgress;

public:

	// DELEGATES

	// Wave Communication
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnPlayerStartWave OnPlayerStartWave;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnWaveStarted OnWaveStarted;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnWaveFinished OnWaveFinished;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnNextWaveReady OnNextWaveReady;

	UPROPERTY(BlueprintCallable)
	FOnWaveInProgress OnWaveInProgress;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnEnemyDeath OnEnemyDeath;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnEnemyReachedEnd OnEnemyReachedEnd;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnStartWaveCountdownTimer OnStartWaveCountdownTimer;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnGameLost OnGameLost;

	// Stats Communication
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnLivesUpdated OnLivesUpdated;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnGoldUpdated OnGoldUpdated;
	
	// Tower Communication
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerBuyRequest OnTowerBuyRequest;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerUpgradeRequest OnTowerUpgradeRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerSellRequest OnTowerSellRequest;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnTowerMoveRequest OnTowerMoveRequest;

	// Functions

public:
	
	/* Subsystem Init */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:

	UFUNCTION()
	void SetWaveInProgress(bool bInWaveInProgress);

	UFUNCTION()
	void OnEnemyReachedEndEvent();

public:
	
	UFUNCTION(BlueprintPure)
	ATdcPlayerState* GetPlayerState();

	UFUNCTION(BlueprintPure)
	ATdcGameState* GetGameState();

	// Gold
	
	UFUNCTION(BlueprintCallable)
	void AddPlayerGold(const int InGoldToAdd);

	UFUNCTION(BlueprintCallable)
	bool SubtractPlayerGold(const int InGoldToSubtract);

	UFUNCTION(BlueprintCallable)
	void SetPlayerGold(const int InGoldToSet);

	// Lives

	UFUNCTION(BlueprintCallable)
	void AddGameLives(const int InLivesToAdd);
	
	UFUNCTION(BlueprintCallable)
	void SubtractGameLives(const int InLivesToSubtract);

	UFUNCTION(BlueprintCallable)
	void SetGameLives(const int InLivesToSet);
	
	// Stats
	
	UFUNCTION(BlueprintCallable)
	void AddPlayerKills(const int InKills);

	UFUNCTION(BlueprintCallable)
	void AddDamageDone(const int InDamageDone);

	UFUNCTION(BlueprintCallable)
	void AddBuildingsSpawned(const int InBuildingSpawned);

	UFUNCTION(BlueprintCallable)
	void AddProjectilesSpawned(const int InProjectilesSpawned);

	// Getters

	UFUNCTION(BlueprintPure)
	int GetPlayerGold();

	UFUNCTION(BlueprintPure)
	int GetGameLives();

	UFUNCTION(BlueprintPure)
	int GetPlayerKills();
	
	UFUNCTION(BlueprintPure)
	float GetPlayerDamageDone();
	
	UFUNCTION(BlueprintPure)
	int GetPlayerBuildingsSpawned();

	UFUNCTION(BlueprintPure)
	int GetPlayerProjectilesSpawned();

	UFUNCTION(BlueprintPure)
	bool GetIsWaveInProgress() const {return bIsWaveInProgress;}

public:

	
};
