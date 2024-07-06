// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "TowerPassive.generated.h"

UCLASS()
class TDC_API ATowerPassive : public ATowerBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "Tower Stats", meta = (ExposeOnSpawn))
	FTowerPassiveStruct TowerPassiveStruct;

	UPROPERTY(BlueprintReadWrite, Category = "Tower Stats")
	FTowerPassiveStats TowerPassiveStats;

public:
	// Sets default values for this actor's properties
	ATowerPassive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tower Stats")
	void SetTowerData(const FTowerPassiveStruct InTowerPassiveStruct) {TowerPassiveStruct = InTowerPassiveStruct;}
};
