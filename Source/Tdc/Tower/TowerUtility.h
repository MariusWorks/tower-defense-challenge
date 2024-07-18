// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TowerUtility.generated.h"

class ATowerOffensive;
class ATowerPassive;
class ATowerBase;

UENUM(BlueprintType)
enum class ETargetingTypes : uint8
{
	First,
	Last,
	Fastest,
	Weakest,
	Strongest
};

UENUM(BlueprintType)
enum class ETowerTypes : uint8
{
	Offensive,
	Defensive,
	Passive
};

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
	Default,
	SpeedReduction,
	DamageOverTime
};

UENUM(BlueprintType)
enum class EPassiveTypes : uint8
{
	Default,
	CooldownReduction,
	IncreaseDamage
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
struct FPassiveEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPassiveTypes PassiveType = EPassiveTypes::Default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EffectPercent = 100.f;
};

USTRUCT(BlueprintType)
struct FTowerStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float DamageDealt = 0.f;

	UPROPERTY(BlueprintReadWrite)
	int Kills = 0;

	UPROPERTY(BlueprintReadWrite)
	int TowersAffected = 0;

	UPROPERTY(BlueprintReadOnly)
	bool bHasTowerBeenUsed = false;

	UPROPERTY(BlueprintReadOnly)
	int UpgradeIndex = 0;

	UPROPERTY(BlueprintReadOnly)
	int MaxUpgradeIndex = 0;
};

USTRUCT(BlueprintType)
struct FTowerData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	int Cost = 0;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	float Range = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cooldown = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SplashRadius = 100.f;

	/* Specify Next Tower Tier if tower should advance to next tier at this upgrade level */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ATowerBase> NextTowerTier;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttack> Attacks;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FAttackEffect> AttackEffects;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAttack> SplashAttacks;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FAttackEffect> SplashAttackEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPassiveEffect> PassiveEffects;
};

USTRUCT(BlueprintType)
struct FTowerStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	FString TowerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETowerTypes TowerType = ETowerTypes::Offensive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor WidgetColor = FLinearColor::White;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TSubclassOf<ATowerBase> TowerClass;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TArray<FTowerData> TowerData;
};

UCLASS()
class UTowerUtility : public UObject
{
	GENERATED_BODY()

public:

	static bool TraceAndUpdatePlot(ATowerBase* InTower, bool bInPlotTaken);
	
};
