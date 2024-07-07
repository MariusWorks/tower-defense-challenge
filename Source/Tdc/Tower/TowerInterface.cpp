// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerInterface.h"

void UTowerInterfaceBridge::OnTowerSelected(UObject* Object)
{
	if (Object && Object->GetClass()->ImplementsInterface(UTowerInterface::StaticClass()))
	{
		ITowerInterface::Execute_OnTowerSelected(Object);
	}
}
