// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Interactables/AlienJDoorInteractable.h"

#include "GameplayTags/AlienJGameplayTags.h"

AAlienJDoorInteractable::AAlienJDoorInteractable()
{
}

void AAlienJDoorInteractable::TryInteract(AActor* Interactor)
{
	Super::TryInteract(Interactor);

	if (InteractableTags.HasTag(TAG_Interaction_Door_Locked))
	{
		UE_LOG(LogTemp, Warning, TEXT("Test: Door is locked. Door tag: %s"), *InteractableTags.ToStringSimple());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Test: TryInteract. Current Door tag: %s"), *InteractableTags.ToStringSimple());
	InteractableTags.HasTag(TAG_Interaction_Door_Opened) ? CloseDoor() : OpenDoor();
}

void AAlienJDoorInteractable::OpenDoor()
{
	if (InteractableTags.HasTag(TAG_Interaction_Door_Closed))
	{
		InteractableTags.RemoveTag(TAG_Interaction_Door_Closed);
		InteractableTags.AddTag(TAG_Interaction_Door_Opened);
		
		UE_LOG(LogTemp, Warning, TEXT("Test: Open the door. Door tag: %s"), *InteractableTags.ToStringSimple());
	}
}

void AAlienJDoorInteractable::CloseDoor()
{
	if (InteractableTags.HasTag(TAG_Interaction_Door_Opened))
	{
		InteractableTags.RemoveTag(TAG_Interaction_Door_Opened);
		InteractableTags.AddTag(TAG_Interaction_Door_Closed);

		UE_LOG(LogTemp, Warning, TEXT("Test: Close the door. Door tag: %s"), *InteractableTags.ToStringSimple());
	}
}
