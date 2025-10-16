// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"

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

UCLASS(Blueprintable, BlueprintType)
class ALIENJOURNEY_API AAlienJBaseInteractableObj : public AActor
{
	GENERATED_BODY()
	
public:	
	AAlienJBaseInteractableObj();
	virtual void Tick(float DeltaTime) override;
	
	int GetInteractableValue() const { return Value; }
	UPrimitiveComponent* GetOverlapVolume() const { return OverlapVolume; }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	TObjectPtr<UStaticMeshComponent> ObjMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	TObjectPtr<USphereComponent> OverlapVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	int Value {0};
		
	/* Methods */
	
	virtual void BeginPlay() override;
};
