// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AlienJBaseCharacter.h"
#include "AlienJAICharacter.generated.h"

/**
 * This class is designed to be the base for all NPCs characters in the game.
 */
UCLASS()
class ALIENJOURNEY_API AAlienJAICharacter : public AAlienJBaseCharacter
{
	GENERATED_BODY()

public:
	AAlienJAICharacter();
};
