// Fill out your copyright notice in the Description page of Project Settings.


#include "TimePeriodGameState.h"
#include "TimeGuesserGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimeGuesserGameMode.h"

void ATimePeriodGameState::StartRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Round Started"));
	if (GetWorld() != nullptr) {
		FTimerDelegate Delegate;
		Delegate.BindUFunction(this, "EndRound", false);
		GetWorld()->GetTimerManager().SetTimer(RoundTimer, Delegate, 15, false);
	}
}

void ATimePeriodGameState::EndRound(bool Won)
{
	UE_LOG(LogTemp, Warning, TEXT("Round Ended"));
	if (GetWorld() != nullptr) {
		GetWorld()->GetTimerManager().ClearTimer(RoundTimer);
	}
	UTimeGuesserGameInstance* TGGameInstance = GetGameInstance<UTimeGuesserGameInstance>();
	if (TGGameInstance) {
		if (Won) {
			TGGameInstance->CurrentLevelName = TGGameInstance->GetRandomTimePeriodLevelName();
			UGameplayStatics::OpenLevel(this, TGGameInstance->CurrentLevelName);
		}
		else {
			ATimeGuesserGameMode* GameMode = GetWorld()->GetAuthGameMode<ATimeGuesserGameMode>();
			if (GameMode) {
				GameMode->EndGame(false);
			}
		}
	}
}
