// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "TowerPassive.generated.h"

UCLASS(Abstract, Blueprintable)
class TDC_API ATowerPassive : public ATowerBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Tower")
	TArray<ATowerBase*> Towers;

public:
	// Sets default values for this actor's properties
	ATowerPassive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void OnTowerPlaced_Implementation() override;

	UFUNCTION()
	virtual bool OnTowerSell_Implementation() override;

	UFUNCTION()
	virtual bool OnTowerMove_Implementation() override;

protected:

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
