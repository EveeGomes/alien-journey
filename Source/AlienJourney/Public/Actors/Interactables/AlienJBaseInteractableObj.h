// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlienJBaseInteractableObj.generated.h"


/*
 * This is the base for all interactable objects.
 * It holds the overlap methods.
 * OnBeginOverlap will take care on setting the InteractableObject which is a variable that lives in the character.
 *	It'll call a function, SetOverlappingObject() that receives this as param. This function comes from the Interactable interface!
 * OnEndOverlap will do the same but instead of sending this as param, it'll send nullptr so InteractableObject variable can be reused.
 */

class UCapsuleComponent;

UCLASS(Blueprintable, BlueprintType)
class ALIENJOURNEY_API AAlienJBaseInteractableObj : public AActor
{
	GENERATED_BODY()
	
public:	
	AAlienJBaseInteractableObj();
	virtual void Tick(float DeltaTime) override;
	
	// int GetInteractableValue() const { return Value; }
	UPrimitiveComponent* GetOverlapVolume() const { return OverlapVolume; }

	// Each child should implement this method with their specific behavior
	// Called from AAlienJPlayerController::Interact()
	// UFUNCTION(BlueprintCallable, Category = "Interation")
	virtual void TryInteract(AActor* Interactor);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	TObjectPtr<UStaticMeshComponent> ObjMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	TObjectPtr<UCapsuleComponent> OverlapVolume;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable | Type")
	FGameplayTagContainer InteractableTags;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactable")
	TObjectPtr<UWidgetComponent> InteractPromptWidget;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	// int Value {0};
		
	/********************** METHODS **********************/
	
	virtual void BeginPlay() override;
	void SetInteractWidgetVisibility(bool Visibility);
	
	/* Collision - Overlap */
	/* Overlap callbacks to be bound to overlap delegates from PrimitiveComponent. */
	// Checks whether OtherActor implements AlienJInteractable interface, and if so calls SetOverlappingObject() passing this.
	UFUNCTION()
	virtual void OnSphereOverlap
	(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	
	// Checks whether OtherActor implements AlienJInteractable interface, and if so calls SetOverlappingObject() passing nullptr.
	UFUNCTION()
	virtual void OnSphereEndOverlap
	(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	);
};