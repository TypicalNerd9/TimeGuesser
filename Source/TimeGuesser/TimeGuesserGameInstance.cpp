// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeGuesserGameInstance.h"
#include "Engine/DataTable.h"
#include <TimeGuesser/StructRegistry.h>

FName UTimeGuesserGameInstance::GetRandomTimePeriodLevelName() {
	TArray<FName> DataTableRowNames = TimePeriodsDataTable->GetRowNames();
	return DataTableRowNames[FMath::RandRange(0, DataTableRowNames.Num()-1)];
}

int UTimeGuesserGameInstance::AddPoints(int Guess)
{
	FTimePeriodStruct* TPStruct = TimePeriodsDataTable->FindRow<FTimePeriodStruct>(CurrentLevelName, "");
	int PointsEarned = 0;
	if (TPStruct) {
		if (TPStruct->StartDate == Guess) {
			PointsEarned = PerfectPointsAmount;
		} else if (TPStruct->StartDate - TPStruct->PerfectPointsBounds <= Guess && Guess <= TPStruct->EndDate + TPStruct->PerfectPointsBounds) {
			PointsEarned = PerfectPointsAmount;
		} else if (TPStruct->StartDate - TPStruct->HighPointsBounds <= Guess && Guess <= TPStruct->EndDate + TPStruct->HighPointsBounds) {
			PointsEarned = HighPointsAmount;
		} else if (TPStruct->StartDate - TPStruct->MediumPointsBounds <= Guess && Guess <= TPStruct->EndDate + TPStruct->MediumPointsBounds) {
			PointsEarned = MediumPointsAmount;
		}
		else if (TPStruct->StartDate - TPStruct->LowPointsBounds <= Guess && Guess <= TPStruct->EndDate + TPStruct->LowPointsBounds) {
			PointsEarned = LowPointsAmount;
		}
		else {
			CurrentGuesses++;
		}
		Points += PointsEarned;
	}
	return PointsEarned;
}
