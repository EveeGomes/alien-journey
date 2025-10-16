// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AlienJDoorInteractionComponent.h"

void UAlienJDoorInteractionComponent::TryInteract(AActor* Interactor)
{
	Super::TryInteract(Interactor);

	bIsOpen ? OpenDoor() : CloseDoor();
}

void UAlienJDoorInteractionComponent::OpenDoor()
{
	if (!bIsOpen)
	{
		bIsOpen = false;

		UE_LOGFMT(LogTemp, Warning, "Test: Open the door.");
	}
}

void UAlienJDoorInteractionComponent::CloseDoor()
{
	if (bIsOpen)
	{
		bIsOpen = false;

		UE_LOGFMT(LogTemp, Warning, "Test: Close the door.");
	}
}
