// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TowerUtility.generated.h"

class ATowerBase;

UENUM(BlueprintType)
enum class EDamageTypes : uint8
{
	Physical,
	Fire,
	Cold,
	Lightning
};

UENUM(BlueprintType)
enum class EEffectTypes : uint8
{
	Default UMETA(DisplayName = "Default"),
	SpeedReduction UMETA(DisplayName = "Speed Reduction"),
	DamageOverTime UMETA(DisplayName = "Damage Over Time"),
	Chaining UMETA(DisplayName = "Chaining1")
};

USTRUCT(BlueprintType)
struct FAttack
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageTypes DamageType = EDamageTypes::Physical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 0.f;
};

USTRUCT(BlueprintType)
struct FAttackEffect
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEffectTypes EffectType = EEffectTypes::Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Effect = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown = 1.f;
};

USTRUCT(BlueprintType)
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
	float Range = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SplashRadius = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttack> Attacks;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FAttackEffect> AttackEffects;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttack> SplashAttacks;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FAttackEffect> SplashAttackEffects;
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
