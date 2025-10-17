// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTags/AlienJGameplayTags.h"
#include "GameplayTagsManager.h"

/**
 * Define and expose gameplay tags declared in .h file to other modules and code. 
 */

UE_DEFINE_GAMEPLAY_TAG(TAG_Interaction_Door_Opened, "Interaction.Door.Opened");
UE_DEFINE_GAMEPLAY_TAG(TAG_Interaction_Door_Closed, "Interaction.Door.Closed");
UE_DEFINE_GAMEPLAY_TAG(TAG_Interaction_Door_Locked, "Interaction.Door.Locked");