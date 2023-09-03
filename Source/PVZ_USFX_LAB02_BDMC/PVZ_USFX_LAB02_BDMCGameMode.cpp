// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB02_BDMCGameMode.h"
#include "PVZ_USFX_LAB02_BDMCPawn.h"

APVZ_USFX_LAB02_BDMCGameMode::APVZ_USFX_LAB02_BDMCGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB02_BDMCPawn::StaticClass();
}

