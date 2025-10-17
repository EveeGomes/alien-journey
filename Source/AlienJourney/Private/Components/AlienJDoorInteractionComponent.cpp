// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/AlienJDoorInteractionComponent.h"

#include "GameplayTags/AlienJGameplayTags.h"


UAlienJDoorInteractionComponent::UAlienJDoorInteractionComponent()
{
}

// void UAlienJDoorInteractionComponent::TryInteract(AActor* Interactor)
// {
// 	Super::TryInteract(Interactor);
//
// 	if (DoorStateTags.HasTag(TAG_Interaction_Door_Locked))
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("Test: Door is locked. Door tag: %s"), *DoorStateTags.ToStringSimple());
// 		return;
// 	}
// 	
// 	DoorStateTags.HasTag(TAG_Interaction_Door_Opened) ? CloseDoor() : OpenDoor();
// }

void UAlienJDoorInteractionComponent::OpenDoor()
{
	if (DoorStateTags.HasTag(TAG_Interaction_Door_Closed))
	{
		DoorStateTags.RemoveTag(TAG_Interaction_Door_Closed);
		DoorStateTags.AddTag(TAG_Interaction_Door_Opened);
		
		UE_LOG(LogTemp, Warning, TEXT("Test: Open the door. Door tag: %s"), *DoorStateTags.ToStringSimple());
	}
}

void UAlienJDoorInteractionComponent::CloseDoor()
{
	if (DoorStateTags.HasTag(TAG_Interaction_Door_Opened))
	{
		DoorStateTags.RemoveTag(TAG_Interaction_Door_Opened);
		DoorStateTags.AddTag(TAG_Interaction_Door_Closed);
		
		UE_LOG(LogTemp, Warning, TEXT("Test: Close the door. Door tag: %s"), *DoorStateTags.ToStringSimple());
	}
}
