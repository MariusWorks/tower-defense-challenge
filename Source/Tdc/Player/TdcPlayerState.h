// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TdcPlayerState.generated.h"

class UGameSubsystem;
/**
 * 
 */
UCLASS()
class TDC_API ATdcPlayerState : public APlayerState
{
	GENERATED_BODY()

	// @RECALL consider putting these inside a replicated struct

	UPROPERTY(Replicated)
	int Gold;

	UPROPERTY(Replicated)
	int Kills;

	UPROPERTY(Replicated)
	float DamageDone;

	UPROPERTY(Replicated)
	int BuildingsSpawned;

	UPROPERTY(Replicated)
	int ProjectilesSpawned;

	UPROPERTY()
	UGameSubsystem* GameSubsystem;

	UFUNCTION()
	UGameSubsystem* GetGameSubsystem();

	UFUNCTION()
	void BroadcastGold();

public:
	
	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void AddGold(const int InGold);

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	bool SubtractGold(const int InGold);

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void SetGold(const int InGold);

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void AddKills(const int InKills) {Kills += InKills;}

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void AddDamageDone (const float InDamageDone) {DamageDone += InDamageDone;}

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void AddBuildingsSpawned(const int InBuildingSpawned) {BuildingsSpawned += InBuildingSpawned;}

	UFUNCTION(BlueprintCallable, Category=PlayerState)
	void AddProjectilesSpawned(const int InProjectilesSpawned) {ProjectilesSpawned += InProjectilesSpawned;}

	// Getters

	

	UFUNCTION(BlueprintPure, Category=PlayerState)
	int GetGold() const {return Gold;}

	UFUNCTION(BlueprintPure, Category=PlayerState)
	int GetKills() const {return Kills;}

	UFUNCTION(BlueprintPure, Category=PlayerState)
	float GetDamageDone() const {return DamageDone;}

	UFUNCTION(BlueprintPure, Category=PlayerState)
	int GetBuildingsSpawned() const {return BuildingsSpawned;}

	UFUNCTION(BlueprintPure, Category=PlayerState)
	int GetProjectilesSpawned() const {return ProjectilesSpawned;}

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
