// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerUtility.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TowerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TDC_API UTowerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTowerSelected, ATowerBase*, InTowerStats);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTowerDeselected);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnTowerSelected OnTowerSelected;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnTowerDeselected OnTowerDeselected;
};
