// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AlienJBaseCharacter.generated.h"

/*
 * Base class for Player and AI/NPC characters.
 * Make it Abstract to prevent it from being used in levels.
 */

UCLASS(Abstract)
class ALIENJOURNEY_API AAlienJBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AAlienJBaseCharacter();

protected:

	virtual void BeginPlay() override;

private:	


};
