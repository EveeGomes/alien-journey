// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AlienJPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"


AAlienJPlayerController::AAlienJPlayerController()
{
	bReplicates = true;
}

void AAlienJPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Assert
	check(AlienJContext);

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubsystem->AddMappingContext(AlienJContext, 0);
	}

	// Mouse cursor
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;

	// Input Mode
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
