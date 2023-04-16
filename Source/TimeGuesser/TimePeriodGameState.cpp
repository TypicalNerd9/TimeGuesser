// Fill out your copyright notice in the Description page of Project Settings.


#include "TimePeriodGameState.h"
#include "TimeGuesserGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimeGuesserGameMode.h"

void ATimePeriodGameState::StartRound()
{
	if (GetWorld() != nullptr) {
			FTimerDelegate Delegate;
			Delegate.BindUFunction(this, "EndRound", false);
			GetWorld()->GetTimerManager().SetTimer(RoundTimer, Delegate, 60, false);
	}
}

