// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeGuesserGameInstance.h"
#include "Engine/DataTable.h"

FName UTimeGuesserGameInstance::GetRandomTimePeriodLevelName() {
	TArray<FName> DataTableRowNames = TimePeriodsDataTable->GetRowNames();
	return DataTableRowNames[FMath::RandRange(0, DataTableRowNames.Num()-1)];
}