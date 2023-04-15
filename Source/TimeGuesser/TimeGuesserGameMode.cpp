// Copyright Epic Games, Inc. All Rights Reserved.

#include "TimeGuesserGameMode.h"
#include "TimeGuesserCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATimeGuesserGameMode::ATimeGuesserGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
