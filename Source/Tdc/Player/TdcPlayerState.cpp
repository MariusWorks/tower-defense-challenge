// Fill out your copyright notice in the Description page of Project Settings.


#include "TdcPlayerState.h"

#include "Tdc/Game/GameSubsystem.h"

void ATdcPlayerState::BeginPlay()
{
	Super::BeginPlay();
	
	UGameSubsystem* GetGameSubsystem = GetGameInstance()->GetSubsystem<UGameSubsystem>();
	if (GetGameSubsystem)
	{
		GameSubsystem = GetGameSubsystem;
	}
}

void ATdcPlayerState::AddGold(const int InGold)
{
	Gold += InGold;
	GameSubsystem->OnGoldUpdated.Broadcast(Gold);
}

bool ATdcPlayerState::SubtractGold(const int InGold)
{
	if (Gold - InGold < 0)
	{
		return false;
	}
	Gold -= InGold;
	GameSubsystem->OnGoldUpdated.Broadcast(Gold);
	return true;
}

void ATdcPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
