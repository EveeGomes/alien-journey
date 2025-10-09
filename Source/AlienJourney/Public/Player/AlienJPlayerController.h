// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "AlienJPlayerController.generated.h"

class UInputMappingContext;

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

private:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> AlienJContext;
};
