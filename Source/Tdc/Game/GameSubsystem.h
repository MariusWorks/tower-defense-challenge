// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameSubsystem.generated.h"

class ATowerBase;
/**
 * 
 */
UCLASS()
class TDC_API UGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivesUpdated, int, InLives);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoldUpdated, int, InGold);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerUpgradeRequest, ATowerBase*, InTowerToUpgrade);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerSellRequest, ATowerBase*, InTowerToSell);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerMoveRequest, ATowerBase*, InTowerToMove);

public:

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
