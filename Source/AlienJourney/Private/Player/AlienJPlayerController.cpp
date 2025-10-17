// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AlienJPlayerController.h"
// #include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/AlienJCharacter.h"
#include "Actors/Interactables/AlienJBaseInteractableObj.h"


AAlienJPlayerController::AAlienJPlayerController()
{
	bReplicates = true;

	//Create InteractionComponent here?
	// InteractionComponent = CreateDefaultSubobject<UAlienJInteractionComponent>(TEXT("InteractionComponent"));
	
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

void AAlienJPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast and check the InputComponent into an EnhancedInputComponent. This way functions to handle data when called, can be bound to Enhanced Input Actions.
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAlienJPlayerController::Move);
	EnhancedInputComponent->BindAction(PressEAction, ETriggerEvent::Started, this, &AAlienJPlayerController::Interact);
}

void AAlienJPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation{0.0f, Rotation.Yaw, 0.0f};

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Move Up or Down
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);

		// Move Right or Left
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAlienJPlayerController::Interact()
{
	AAlienJCharacter* AlienCharacter = Cast<AAlienJCharacter>(GetPawn());
	if (AlienCharacter && AlienCharacter->GetCurrentInteractableObj())
	{
		AlienCharacter->GetCurrentInteractableObj()->TryInteract(AlienCharacter);
		UE_LOG(LogTemp, Display, TEXT("Test: AlienJ Interact with %s"), *AlienCharacter->GetCurrentInteractableObj()->GetName());
	}
	
	// // Get the character
	// // Check if it's a BaseInteractableObj
	// // if so, print a message log
	// AAlienJCharacter* AlienCharacter = Cast<AAlienJCharacter>(GetPawn());
	// if (AlienCharacter && AlienCharacter->GetInteractableObject())
	// {
	// 	UE_LOG(LogTemp, Display, TEXT("AlienJ Interact"));
	// 	AlienCharacter->SetCollectableAmount(AlienCharacter->GetInteractableObject()->GetInteractableValue());
	// }
}
