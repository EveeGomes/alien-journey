// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AlienJInteractionComponent.h"
#include "Actors/Interactables/AlienJBaseInteractableObj.h"
#include "Character/AlienJCharacter.h"
#include "Interface/AlienJInteractable.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"

UAlienJInteractionComponent::UAlienJInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UAlienJInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// const AAlienJBaseInteractableObj* OwnerObject = Cast<AAlienJBaseInteractableObj>(GetOwner());
	// if (OwnerObject && OwnerObject->GetOverlapVolume())
	// {
	// 	CollisionComponent = OwnerObject->GetOverlapVolume();
	// 	UE_LOG(LogTemp, Warning, TEXT("Test: Assigned OverlapVolume from owner: %s"), *GetNameSafe(CollisionComponent));
	// }
	// else
	// {
	// 	CollisionComponent = FindBestCollisionComponent();
	// 	UE_LOG(LogTemp, Warning, TEXT("Test: Fallback to auto-detected collision component: %s"), *GetNameSafe(CollisionComponent));
	// }
	
	// // Bind to overlap delegates
	// CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UAlienJInteractionComponent::OnSphereOverlap);
	// CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &UAlienJInteractionComponent::OnSphereEndOverlap);
}

// void UAlienJInteractionComponent::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	if (!OtherActor || OtherActor == GetOwner()) return;
// 	
// 	// If OtherActor implements AlienJInteractable, store its reference
// 	if (OtherActor->GetClass()->ImplementsInterface(UAlienJInteractable::StaticClass()))
// 	{
// 		UE_LOGFMT(LogTemp, Warning, "Test: Begin overlap, set refs.");
// 		UE_LOG(LogTemp, Warning, TEXT("Overlapping component: %s"), *OtherComp->GetName());
//
// 		/*
// 		 * TODO: maybe these references aren't needed!
// 		 *	All it needs it to get the Interactor, check if it's a player and call a "Collected(collectableTag)" method
// 		 *	that will check the tag and increase the corresponding resource (wood or gold or water etc).
// 		 * So, this object doesn't need to know about the Interactor nor the Interactor needs a reference to this object if
// 		 *  it knows what type of resource it represents (that can be done through its tag!).
// 		 */
// 		
// 		CurrentInteractor = TScriptInterface<IAlienJInteractable>(OtherActor);
// 		// Let the interactor know about the interactable obj
// 		CurrentInteractor->SetCurrentInteractable(this);
// 		
// 		// Also, show a widget to indicate it can be interacted with by pressing E.
//         // Only after pressing E, it should add to the player or do whatever it needs.
//
// 		AAlienJCharacter* Player = Cast<AAlienJCharacter>(CurrentInteractor.GetObject());
// 		if (Player && Player->InteractPromptWidget)
// 		{
// 			Player->SetInteractWidgetVisibility(true);
// 		}
// 	}
// }

// void UAlienJInteractionComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	if (!OtherActor || OtherActor == GetOwner()) return;
// 	
// 	if (OtherActor->GetClass()->ImplementsInterface(UAlienJInteractable::StaticClass()))
//     {
// 		// Only clear reference if the actor leaving is the same as the stored one
// 		if (CurrentInteractor && OtherActor == CurrentInteractor.GetObject())
// 		{
// 			AAlienJCharacter* Player = Cast<AAlienJCharacter>(CurrentInteractor.GetObject());
// 			if (Player && Player->InteractPromptWidget)
// 			{
// 				Player->SetInteractWidgetVisibility(false);
// 				UE_LOGFMT(LogTemp, Warning, "Test: End overlap, set widget visibility to false");
// 			}
//
// 			// Set references to nullptr - both the Interactor and Interactable
//             CurrentInteractor->SetCurrentInteractable(nullptr);	
//             CurrentInteractor = nullptr;
//             UE_LOGFMT(LogTemp, Warning, "Test: End overlap, set refs to null");
// 		}
//     }
// }

// UPrimitiveComponent* UAlienJInteractionComponent::FindBestCollisionComponent()
// {
// 	AActor* OwnerActor = GetOwner();
// 	if (!OwnerActor) return nullptr;
//
// 	TArray<UPrimitiveComponent*> PossibleComponents;
// 	OwnerActor->GetComponents<UPrimitiveComponent>(PossibleComponents);
// 	
// 	UPrimitiveComponent* FallbackComponent = nullptr;
// 	
// 	for (UPrimitiveComponent* Component : PossibleComponents)
// 	{
// 		if (!Component) continue;
//
// 		// Check if overlap events is enabled
// 		if (Component->GetGenerateOverlapEvents() && Component->IsCollisionEnabled())
// 		{
// 			// Prioritize specific types? It should return the first preferred match <<<<<<<<<<<<<<<<<<<<
// 			if (Component->IsA(USphereComponent::StaticClass()) ||
// 				Component->IsA(UBoxComponent::StaticClass()) ||
// 				Component->IsA(UCapsuleComponent::StaticClass()))
// 			{
// 				UE_LOGFMT(LogTemp, Warning, "Test: Found component: {0}", Component->GetName());
// 				return Component;
// 			}
//
// 			// Store as fallback for not preferred type is found
// 			if (!FallbackComponent)
// 			{
// 				FallbackComponent = Component;
// 			}
// 		}
// 	}
//
// 	UE_LOGFMT(LogTemp, Warning, "Test: Return FallbackComponent: {0}", FallbackComponent->GetName());
// 	return FallbackComponent;
//
// 	// // Fallback: return any valid collision-enabled primitive? <<<<<<<<<<<<<<<<<<<<
// 	// for (UPrimitiveComponent* Component : PossibleComponents)
// 	// {
// 	// 	if (Component->GetGenerateOverlapEvents() && Component->IsCollisionEnabled())
// 	// 	{
// 	// 		return Component;
// 	// 	}
// 	// }
// 	
// 	// return nullptr;
// }

// UPrimitiveComponent* UAlienJInteractionComponent::GetBestCollisionComponent()
// {
// 	return CollisionComponent.Get() ? CollisionComponent.Get() : FindBestCollisionComponent();
// }

// Called every frame
void UAlienJInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// void UAlienJInteractionComponent::TryInteract(AActor* Interactor)
// {
// 	if (!Interactor) return;
// }

