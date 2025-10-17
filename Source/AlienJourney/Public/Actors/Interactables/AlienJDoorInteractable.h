// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactables/AlienJBaseInteractableObj.h"
#include "AlienJDoorInteractable.generated.h"

/**
 * 
 */
UCLASS()
class ALIENJOURNEY_API AAlienJDoorInteractable : public AAlienJBaseInteractableObj
{
	GENERATED_BODY()

public:
	AAlienJDoorInteractable();
	
	virtual void TryInteract(AActor* Interactor) override;
	
protected:
	
	void OpenDoor();
	void CloseDoor();
};
