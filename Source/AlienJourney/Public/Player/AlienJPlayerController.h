// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/AlienJInteractionComponent.h"
#include "GameFramework/PlayerController.h"

#include "AlienJPlayerController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * Used to associate the Enhanced Input Action(s) and Input Mapping Context(s), assets created in the editor, with a character.
 */
UCLASS()
class ALIENJOURNEY_API AAlienJPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAlienJPlayerController();

	
protected:
	// Add the IMC
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AlienJContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> PressEAction;

	/********************** METHODS **********************/

	// Internal function that handles input coming from input action, MoveAction
	void Move(const FInputActionValue& InputActionValue);

	// Should call Interact() from InteractionComponent?
	void Interact();
};