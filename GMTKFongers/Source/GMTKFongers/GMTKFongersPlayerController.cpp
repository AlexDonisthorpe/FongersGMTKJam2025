// Copyright Epic Games, Inc. All Rights Reserved.


#include "GMTKFongersPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "GMTKFongersCameraManager.h"

AGMTKFongersPlayerController::AGMTKFongersPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AGMTKFongersCameraManager::StaticClass();
}

void AGMTKFongersPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
