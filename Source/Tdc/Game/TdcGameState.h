// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TdcGameState.generated.h"

class UGameSubsystem;
/**
 * 
 */
UCLASS()
class TDC_API ATdcGameState : public AGameState
{
	GENERATED_BODY()

	UPROPERTY()
	int Lives;

	UPROPERTY()
	UGameSubsystem* GameSubsystem;

	UFUNCTION()
	UGameSubsystem* GetGameSubsystem();

	UFUNCTION()
    void BroadcastLives();

public:

	UFUNCTION(BlueprintCallable, Category=GameState)
	void SetLives(const int InLives);

	UFUNCTION(BlueprintCallable, Category=GameState)
	void AddLives(const int InLives);

	UFUNCTION(BlueprintCallable, Category=GameState)
	void SubtractLives(const int InLives);

	UFUNCTION(BlueprintPure, Category=GameState)
	int GetLives() const {return Lives;}
	
};
