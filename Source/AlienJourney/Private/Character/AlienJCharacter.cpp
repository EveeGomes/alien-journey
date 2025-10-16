// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AlienJCharacter.h"
#include "Components/WidgetComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

AAlienJCharacter::AAlienJCharacter()
{
	// Create and set the widget
	InteractPromptWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractPromtWidget"));
	InteractPromptWidget->SetupAttachment(RootComponent);
	// InteractPromptWidget->SetWidgetClass() // via BP?
	InteractPromptWidget->SetVisibility(false);
	
	// Typical set up for a Top-Down game
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator{0.f, 400.f, 0.f};
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAlienJCharacter::SetInteractWidgetVisibility(bool Visibility)
{
	InteractPromptWidget->SetVisibility(Visibility);
}

UAlienJInteractionComponent* AAlienJCharacter::GetInteractionComponent()
{
	if (CurrentInteractionComponent)
	{
		return CurrentInteractionComponent;
	}

	return nullptr;
}

void AAlienJCharacter::SetCollectableAmount(const int InAmount)
{
	if (InAmount > 0)
	{
		CollectableAmount += InAmount;
		UE_LOG(LogTemp, Warning, TEXT("Test: collectable amount: %d"), CollectableAmount);
	}
}

void AAlienJCharacter::SetCurrentInteractable(UAlienJInteractionComponent* InteractableComponent)
{
	// IAlienJInteractable::SetCurrentInteractable_Implementation(InteractableComponent);
	
	CurrentInteractionComponent = InteractableComponent;
}