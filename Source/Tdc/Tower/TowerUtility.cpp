// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerUtility.h"

#include "TowerBase.h"
#include "Tdc/Plot/TowerPlot.h"

bool UTowerUtility::TraceAndUpdatePlot(ATowerBase* InTower, bool bInPlotTaken)
{
	if (!InTower || !InTower->GetWorld())
	{
		return false;
	}
	
	FHitResult HitResult;
	FVector StartLocation = InTower->GetActorLocation();
	FVector EndLocation = StartLocation - FVector(0.f, 0.f, 500.f);
	FCollisionObjectQueryParams CollisionObjectQueryParams;
	CollisionObjectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
	CollisionObjectQueryParams.AddObjectTypesToQuery(ECC_GameTraceChannel3);
	FCollisionQueryParams CollisionQueryParams;

	if (InTower->GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, CollisionObjectQueryParams, CollisionQueryParams))
	{
		if (HitResult.GetActor() && HitResult.GetComponent())
		{
			if (ATowerPlot* TowerPlot = Cast<ATowerPlot>(HitResult.GetActor()))
			{
				TowerPlot->UpdateTowerPlot(HitResult.GetComponent(), bInPlotTaken);
				return true;
			}
		}
	}
	
	return false;
}
