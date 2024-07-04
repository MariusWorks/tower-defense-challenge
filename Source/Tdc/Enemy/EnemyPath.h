// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "EnemyPath.generated.h"

UCLASS()
class TDC_API AEnemyPath : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Path")
	USplineComponent* SplineComponent;

public:

	AEnemyPath();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
