// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyUtility.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

UCLASS()
class TDC_API AEnemyBase : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enemy Data")
	FEnemyData EnemyData;

public:
	// Sets default values for this actor's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Getters
	UFUNCTION(BlueprintPure, Category = "Enemy Data")
	FEnemyData& GetEnemyData() {return EnemyData;}
};
