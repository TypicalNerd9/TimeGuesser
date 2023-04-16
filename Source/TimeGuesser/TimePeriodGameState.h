// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TimePeriodGameState.generated.h"

/**
 * 
 */
UCLASS()
class TIMEGUESSER_API ATimePeriodGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTimerHandle RoundTimer;

	UFUNCTION(BlueprintCallable)
		void StartRound();

	UFUNCTION(BlueprintCallable)
		void EndRound(bool Won);
};
