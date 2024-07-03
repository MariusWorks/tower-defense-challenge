// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TowerUtility.generated.h"

class ATowerBase;

USTRUCT(BlueprintType, Blueprintable)
struct FTowerStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float DamageDealt = 0.f;

	UPROPERTY(BlueprintReadWrite)
	int NumberKills = 0;
};

USTRUCT(BlueprintType)
struct FTowerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cost = 0;
	
	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	float Damage = 0.f;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	float Range = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldSplash = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SplashDamage = 0.f;
};

USTRUCT(BlueprintType)
struct FTowerCollection : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	FString TowerName;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TSubclassOf<ATowerBase> TowerType;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FTowerData> TowerData;
};
