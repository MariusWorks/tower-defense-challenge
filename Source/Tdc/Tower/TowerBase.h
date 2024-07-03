// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerUtility.h"
#include "GameFramework/Actor.h"
#include "TowerBase.generated.h"

UCLASS()
class TDC_API ATowerBase : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "Tower Stats")
	FTowerStats TowerStats;

	UPROPERTY(BlueprintReadOnly, Category = "Tower Stats", meta = (ExposeOnSpawn))
	FTowerData TowerData;

	UPROPERTY(BlueprintReadOnly, Category = "Tower Stats", meta = (ExposeOnSpawn))
	FDataTableRowHandle TowerRowHandle;

	UPROPERTY(BlueprintReadWrite, Category = "Tower State")
	bool bTowerActive;

	UPROPERTY(BlueprintReadWrite, Category = "Tower State")
	int TowerUpgradeIndex;

	UPROPERTY(BlueprintReadWrite, Category = "Tower State", meta = (ExposeOnSpawn))
	int MaxTowerUpgradeIndex;

public:
	// Sets default values for this actor's properties
	ATowerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tower Stats")
	void SetTowerData(const FTowerData InTowerData) {TowerData = InTowerData;}
};
