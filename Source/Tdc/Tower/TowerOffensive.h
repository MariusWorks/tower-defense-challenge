// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "TowerOffensive.generated.h"

UCLASS()
class TDC_API ATowerOffensive : public ATowerBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower", meta = (AllowPrivateAccess))
	USceneComponent* ProjectileSpawn;

public:

	UPROPERTY(BlueprintReadOnly, Category = "Tower Stats", meta = (ExposeOnSpawn))
	FTowerOffensiveStruct TowerOffensiveStruct;

	UPROPERTY(BlueprintReadWrite, Category = "Tower Stats")
	FTowerOffensiveStats TowerOffensiveStats;

public:
	// Sets default values for this actor's properties
	ATowerOffensive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tower Stats")
	void SetTowerData(const FTowerOffensiveStruct InTowerOffensiveStruct) {TowerOffensiveStruct = InTowerOffensiveStruct;}
};
