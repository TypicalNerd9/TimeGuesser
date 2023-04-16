// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "StructRegistry.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTimePeriodStruct : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int StartDate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int EndDate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString LevelName;
};
