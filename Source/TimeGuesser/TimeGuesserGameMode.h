// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeGuesserGameMode.generated.h"

UCLASS(minimalapi)
class ATimeGuesserGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATimeGuesserGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void EndGame(bool Won);
};



