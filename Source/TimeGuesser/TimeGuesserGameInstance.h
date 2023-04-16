// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "TimeGuesserGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TIMEGUESSER_API UTimeGuesserGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Periods Info")
		UDataTable* TimePeriodsDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Periods Info")
		FName CurrentLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Periods Info")
		int TimeToGuess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int CurrentGuesses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int MaxGuesses;

	UFUNCTION(BlueprintCallable)
		FName GetRandomTimePeriodLevelName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int PointsToWin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int PerfectPointsAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int HighPointsAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int MediumPointsAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Info")
		int LowPointsAmount;

	UFUNCTION(BlueprintCallable)
		int AddPoints(int Guess);
	
};
