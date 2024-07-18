// Fill out your copyright notice in the Description page of Project Settings.


#include "TdcGameState.h"

#include "GameSubsystem.h"

UGameSubsystem* ATdcGameState::GetGameSubsystem()
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

void ATdcGameState::BroadcastLives()
{
	if (const UGameSubsystem* MyGameSubsystem = GetGameSubsystem())
	{
		MyGameSubsystem->OnLivesUpdated.Broadcast(Lives);
		if (Lives <= 0)
		{
			MyGameSubsystem->OnGameLost.Broadcast();
		}
	}
}

void ATdcGameState::SetLives(const int InLives)
{
	Lives = InLives;
	BroadcastLives();
}

void ATdcGameState::AddLives(const int InLives)
{
	Lives += InLives;
	BroadcastLives();
}

void ATdcGameState::SubtractLives(const int InLives)
{
	Lives -= InLives;
	BroadcastLives();
}