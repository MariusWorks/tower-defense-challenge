// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnemyUtility.generated.h"

class AEnemyBase;

USTRUCT(BlueprintType)
struct FEnemyData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float CurrentHealth = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KillReward = 1;
	
};

USTRUCT(BlueprintType)
struct FCycleUnit
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TSubclassOf<AEnemyBase> EnemyClass;
	
	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	int NumberToSpawn = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnDelay = 1.f;
};

USTRUCT(BlueprintType)
struct FCycle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FCycleUnit> CycleUnits;
};

USTRUCT(BlueprintType)
struct FLevelWaves : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* LevelImage;

	UPROPERTY(EditAnywhere ,BlueprintReadOnly)
	FCycle Cycle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int LevelCycles = 5;

	/* Percent Increase in 0.1 format */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ScalingMultiplier = 0.1f;

	UPROPERTY(EditAnywhere ,BlueprintReadOnly)
	int StartingGold = 50;

	UPROPERTY(EditAnywhere ,BlueprintReadOnly)
	int StartingLives = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TimeBetweenWaves = 30.f;
};
