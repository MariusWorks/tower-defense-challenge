// Fill out your copyright notice in the Description page of Project Settings.


#include "TdcPlayerState.h"

#include "Tdc/Game/GameSubsystem.h"

UGameSubsystem* ATdcPlayerState::GetGameSubsystem()
{
	if (GameSubsystem)
	{
		return GameSubsystem;
	}
	else
	{
		if (UGameSubsystem* GetGameSubsystem = GetGameInstance()->GetSubsystem<UGameSubsystem>())
		{
			GameSubsystem = GetGameSubsystem;
			return GameSubsystem;
		}
		else
		{
			UE_LOG(LogActor, Error, TEXT("Could not get Subsystem from GameInstance!"));
			return nullptr;
		}
	}
}

void ATdcPlayerState::BroadcastGold()
{
	if (const UGameSubsystem* MyGameSubsystem = GetGameSubsystem())
	{
		MyGameSubsystem->OnGoldUpdated.Broadcast(Gold);
	}
}

void ATdcPlayerState::AddGold(const int InGold)
{
	Gold += InGold;
	BroadcastGold();
}

bool ATdcPlayerState::SubtractGold(const int InGold)
{
	if (Gold - InGold < 0)
	{
		return false;
	}
	Gold -= InGold;
	BroadcastGold();
	return true;
}

void ATdcPlayerState::SetGold(const int InGold)
{
	Gold = InGold;
	BroadcastGold();
}

void ATdcPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
