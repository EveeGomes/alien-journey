// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AlienJInteractable.generated.h"

class UAlienJInteractionComponent;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAlienJInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

// Forward Declarations
class AAlienJBaseInteractableObj;

class ALIENJOURNEY_API IAlienJInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//TODO: CHECK LESSON 106 OR BEFORE TO SEE THE BEST APPROACH ON IMPLEMENTING THINGS LIKE IDENTIFYING OBJECTS TO INTERACT WITH!

	// OnBeginFocus()
	// OnEndFocus()
	// GetInteractText()

	// /* Called when the player interacts with an object. */ 
	// UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	// void OnInteract(AActor* InteractActor);

	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	virtual void SetCurrentInteractableObj(AAlienJBaseInteractableObj* InteractableObj) = 0;
	
};
