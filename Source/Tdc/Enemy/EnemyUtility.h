// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnemyUtility.generated.h"

class AEnemyBase;

USTRUCT(BlueprintType)
struct FWaveUnit
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	//TSoftClassPtr<AEnemyBase> EnemySubclass;
	TSubclassOf<AEnemyBase> EnemyClass;
	
	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	int NumberToSpawn = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnDelay = 1.f;
};

USTRUCT(BlueprintType)
struct FWave
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FWaveUnit> WaveUnits;
};

USTRUCT(BlueprintType)
struct FLevelWaves : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FWave> Waves;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	int StartingGold = 50;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	int StartingLives = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeBetweenWaves = 30.f;
};
