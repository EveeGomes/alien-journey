// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AlienJCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAlienJCharacter::AAlienJCharacter()
{
	// Typical set up for a Top-Down game
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator{0.f, 400.f, 0.f};
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
