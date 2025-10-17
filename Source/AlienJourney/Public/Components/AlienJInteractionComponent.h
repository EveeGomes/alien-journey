// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*
 * This component encapsulates interaction logic. It should be attachable to any actor (collectables, breakables, doors etc.)
 * It handles:
 *	- overlap detection
 *	- interaction triggers
 *	- state management
 */

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AlienJInteractionComponent.generated.h"


class IAlienJInteractable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALIENJOURNEY_API UAlienJInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	/********************** METHODS **********************/
	
	// Sets default values for this component's properties
	UAlienJInteractionComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// // Called from AAlienJPlayerController::Interact()
	// // UFUNCTION(BlueprintCallable, Category = "Interation")
	// virtual void TryInteract(AActor* Interactor);
	
protected:
	// Used by the actor to trigger overlaps. Also used to bind to overlap delegates.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction | Collision")
	TObjectPtr<UPrimitiveComponent> CollisionComponent;
	
	
	/********************** METHODS **********************/

	// Bind callbacks to CollisionComponent overlap delegates.
	virtual void BeginPlay() override;

	// /* Collision - Overlap */
	// /* Overlap callbacks to be bound to overlap delegates from PrimitiveComponent. */
	// // Checks whether OtherActor implements AlienJInteractable interface, and if so calls SetOverlappingObject() passing this.
	// UFUNCTION()
	// virtual void OnSphereOverlap
	// (
	// 	UPrimitiveComponent* OverlappedComponent,
	// 	AActor* OtherActor,
	// 	UPrimitiveComponent* OtherComp,
	// 	int32 OtherBodyIndex,
	// 	bool bFromSweep,
	// 	const FHitResult& SweepResult
	// );
	//
	// // Checks whether OtherActor implements AlienJInteractable interface, and if so calls SetOverlappingObject() passing nullptr.
	// UFUNCTION()
	// virtual void OnSphereEndOverlap
	// (
	// 	UPrimitiveComponent* OverlappedComponent,
	// 	AActor* OtherActor,
	// 	UPrimitiveComponent* OtherComp,
	// 	int32 OtherBodyIndex
	// );

private:
	/* Configuration */

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRange { 300.0f };

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRadius { 50.0f };

	/* Tracking */
	// Actor that has overlapped and implements Interactable interface
	UPROPERTY()
	TScriptInterface<IAlienJInteractable> CurrentInteractor;
	
	/********************** METHODS **********************/
	/* Collision */
	// Iterates over all components on the owner actor to find the best component for collision/overlapping events
	// UPrimitiveComponent* FindBestCollisionComponent();
	// UPrimitiveComponent* GetBestCollisionComponent();


	// void PerformTrace();
	// void UpdateFocus(TScriptInterface<IAlienJInteractable> NewInteractable);
};
