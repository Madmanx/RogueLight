// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RogueLightGameMode.h"
#include "RogueLightHUD.h"
#include "RogueLightCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARogueLightGameMode::ARogueLightGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARogueLightHUD::StaticClass();
}
