// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ArraySorter.generated.h"

/**
 * 
 */
UCLASS()
class TDC_API UArraySorter : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static TMap<AActor*, float> SortActorDistanceMap(TMap<AActor*, float> InActorDistanceMap);
};
