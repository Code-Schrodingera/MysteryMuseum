// Copyright Epic Games, Inc. All Rights Reserved.

#include "MysteryMuseumGameMode.h"
#include "MysteryMuseumPlayerController.h"
#include "MysteryMuseumCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMysteryMuseumGameMode::AMysteryMuseumGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMysteryMuseumPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}