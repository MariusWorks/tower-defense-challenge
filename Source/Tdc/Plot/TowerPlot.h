// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "TowerPlot.generated.h"

UCLASS()
class TDC_API ATowerPlot : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plot", meta = (AllowPrivateAccess))
	UStaticMeshComponent* TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plot", meta = (AllowPrivateAccess))
	UBoxComponent* Box1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plot", meta = (AllowPrivateAccess))
	UBoxComponent* Box2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plot", meta = (AllowPrivateAccess))
	UBoxComponent* Box3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plot", meta = (AllowPrivateAccess))
	UBoxComponent* Box4;

	UPROPERTY()
	TMap<UPrimitiveComponent*, bool> BoxMap;

public:

	ATowerPlot();

protected:

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, Category = "Tower Plot")
	bool UpdateTowerPlot(UPrimitiveComponent* InBoxComponent, bool bInPlotTaken);

	UFUNCTION(BlueprintCallable, Category = "Tower Plot")
	bool IsPlotTaken(UPrimitiveComponent* InBoxComponent);

};
