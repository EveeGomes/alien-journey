// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AlienJInteractionComponent.h"
#include "AlienJDoorInteractionComponent.generated.h"

/**
 * 
 */
UCLASS()
class ALIENJOURNEY_API UAlienJDoorInteractionComponent : public UAlienJInteractionComponent
{
	GENERATED_BODY()

public:
	UAlienJDoorInteractionComponent();

	virtual void TryInteract(AActor* Interactor) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Door")
	bool bIsOpen;

	UFUNCTION()
	void OpenDoor();

	UFUNCTION()
	void CloseDoor();
};
