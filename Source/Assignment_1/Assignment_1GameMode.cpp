// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Assignment_1GameMode.h"
#include "Assignment_1HUD.h"
#include "Assignment_1Character.h"
#include "UObject/ConstructorHelpers.h"

AAssignment_1GameMode::AAssignment_1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	static ConstructorHelpers::FClassFinder<AHUD> HUDFinder(TEXT("/Game/MyHUD"));
	HUDClass = HUDFinder.Class;
}
