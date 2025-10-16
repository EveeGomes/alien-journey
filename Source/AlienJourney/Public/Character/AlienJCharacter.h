// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "Actors/Interactables/AlienJBaseInteractableObj.h"
#include "Interface/AlienJInteractable.h"

#include "CoreMinimal.h"
#include "Character/AlienJBaseCharacter.h"
#include "Components/AlienJInteractionComponent.h"
#include "AlienJCharacter.generated.h"

class UWidgetComponent;

/**
 * This class is designed to create the Player character.
 */
UCLASS()
class ALIENJOURNEY_API AAlienJCharacter : public AAlienJBaseCharacter, public IAlienJInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactable")
	TObjectPtr<UWidgetComponent> InteractPromptWidget;
	
	AAlienJCharacter();
	void SetInteractWidgetVisibility(bool Visibility);

	UAlienJInteractionComponent* GetInteractionComponent();	

	void SetCollectableAmount(int InAmount);
	int GetCollectableAmount() const { return CollectableAmount; }

	// AAlienJBaseInteractableObj* GetInteractableObject() { return InteractableObject; }

protected:
	virtual void SetCurrentInteractable(UAlienJInteractionComponent* InteractableComponent) override;
	
private:
	// UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
	int CollectableAmount {0};
	
	UPROPERTY(VisibleAnywhere, Category = "Interactable", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAlienJInteractionComponent> CurrentInteractionComponent;
};
