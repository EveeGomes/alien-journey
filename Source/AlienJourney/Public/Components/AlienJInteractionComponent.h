// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AlienJInteractionComponent.generated.h"


class IAlienJInteractable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALIENJOURNEY_API UAlienJInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAlienJInteractionComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called via input binding
	UFUNCTION(BlueprintCallable, Category = "Interation")
	void Interact();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	/* Configuration */

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRange { 300.0f };

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRadius { 50.0f };

	/* Tracking */
	UPROPERTY()
	TScriptInterface<IAlienJInteractable> CurrentInteractable;

	void PerformTrace();
	void UpdateFocus(TScriptInterface<IAlienJInteractable> NewInteractable);
};
