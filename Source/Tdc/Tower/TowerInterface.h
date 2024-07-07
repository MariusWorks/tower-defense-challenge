// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TowerInterface.generated.h"

UCLASS()
class UTowerInterfaceBridge : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void OnTowerSelected(UObject* Object);
	
};

UINTERFACE(Blueprintable)
class UTowerInterface : public UInterface
{
	GENERATED_BODY()
};

class ITowerInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerPlaced();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	bool OnTowerUpgrade();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	bool OnTowerSell();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	bool OnTowerMove();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerSelected();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerDeselected();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerDamageDealt(float InDamageDealt);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerKill();

	// @RECALL Figure out what to do with these
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerApplyBuff();

	// @RECALL Figure out what to do with these
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Tower")
	void OnTowerRemoveBuff();
};
