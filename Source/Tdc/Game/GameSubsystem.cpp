// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSubsystem.h"

#include "TdcGameState.h"
#include "GameFramework/GameModeBase.h"
#include "Tdc/Player/TdcPlayerState.h"

void UGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	OnWaveInProgress.AddDynamic(this, &UGameSubsystem::SetWaveInProgress);
	OnEnemyReachedEnd.AddDynamic(this, &UGameSubsystem::UGameSubsystem::OnEnemyReachedEndEvent);
}

void UGameSubsystem::SetWaveInProgress(const bool bInWaveInProgress)
{
	bIsWaveInProgress = bInWaveInProgress;
}

void UGameSubsystem::OnEnemyReachedEndEvent()
{
	if (GetGameState())
	{
		GameState->SubtractLives(1);
	}
}

ATdcPlayerState* UGameSubsystem::GetPlayerState()
{
	if (!GetWorld() || !GetWorld()->GetFirstPlayerController())
	{
		UE_LOG(LogActor, Error, TEXT("GameSubsystem: Unable to get World or PlayerController!"))
		return nullptr;
	}
	
	if (PlayerState)
	{
		return PlayerState;
	}

	ATdcPlayerState* MyPlayerState = GetWorld()->GetFirstPlayerController()->GetPlayerState<ATdcPlayerState>();
	if (MyPlayerState)
	{
		PlayerState = MyPlayerState;
		return MyPlayerState;
	}
	
	return nullptr;
}

ATdcGameState* UGameSubsystem::GetGameState()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		UE_LOG(LogActor, Error, TEXT("GameSubsystem: Unable to get World or Gamemode!"))
		return nullptr;
	}
	
	if (GameState)
	{
		return GameState;
	}
	
	ATdcGameState* MyGameState = GetWorld()->GetAuthGameMode()->GetGameState<ATdcGameState>();
	if (MyGameState)
	{
		GameState = MyGameState;
		return MyGameState;
	}
	
	return nullptr;
}

void UGameSubsystem::AddPlayerGold(const int InGoldToAdd)
{
	if (GetPlayerState())
	{
		PlayerState->AddGold(InGoldToAdd);
	}
}

bool UGameSubsystem::SubtractPlayerGold(const int InGoldToSubtract)
{
	if (GetPlayerState())
	{
		return PlayerState->SubtractGold(InGoldToSubtract);
	}
	return false;
}

void UGameSubsystem::SetPlayerGold(const int InGoldToSet)
{
	if (GetPlayerState())
	{
		PlayerState->SetGold(InGoldToSet);
	}
}

void UGameSubsystem::AddGameLives(const int InLivesToAdd)
{
	if (GetGameState())
	{
		GameState->AddLives(InLivesToAdd);
	}
}

void UGameSubsystem::SubtractGameLives(const int InLivesToSubtract)
{
	if (GetGameState())
	{
		GameState->SubtractLives(InLivesToSubtract);
	}
}

void UGameSubsystem::SetGameLives(const int InLivesToSet)
{
	if (GetGameState())
	{
		GameState->SetLives(InLivesToSet);
	}
}

void UGameSubsystem::AddPlayerKills(const int InKills)
{
	if (GetPlayerState())
	{
		PlayerState->AddKills(InKills);
	}
}

void UGameSubsystem::AddDamageDone(const int InDamageDone)
{
	if (GetPlayerState())
	{
		PlayerState->AddDamageDone(InDamageDone);
	}
}

void UGameSubsystem::AddBuildingsSpawned(const int InBuildingSpawned)
{
	if (GetPlayerState())
	{
		PlayerState->AddBuildingsSpawned(InBuildingSpawned);
	}
}

void UGameSubsystem::AddProjectilesSpawned(const int InProjectilesSpawned)
{
	if (GetPlayerState())
	{
		PlayerState->AddProjectilesSpawned(InProjectilesSpawned);
	}
}

int UGameSubsystem::GetPlayerGold()
{
	if (GetPlayerState())
	{
		return PlayerState->GetGold();
	}
	return -1;
}

int UGameSubsystem::GetGameLives()
{
	if (GetGameState())
	{
		return GameState->GetLives();
	}
	return -1;
}

int UGameSubsystem::GetPlayerKills()
{
	if (GetPlayerState())
	{
		return PlayerState->GetKills();
	}
	return -1;
}

float UGameSubsystem::GetPlayerDamageDone()
{
	if (GetPlayerState())
	{
		return PlayerState->GetDamageDone();
	}
	return -1.f;
}

int UGameSubsystem::GetPlayerBuildingsSpawned()
{
	if (GetPlayerState())
	{
		return PlayerState->GetBuildingsSpawned();
	}
	return -1;
}

int UGameSubsystem::GetPlayerProjectilesSpawned()
{
	if (GetPlayerState())
	{
		return PlayerState->GetProjectilesSpawned();
	}
	return -1;
}