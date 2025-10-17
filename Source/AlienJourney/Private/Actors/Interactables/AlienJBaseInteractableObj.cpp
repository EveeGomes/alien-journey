// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Interactables/AlienJBaseInteractableObj.h"

#include "Character/AlienJCharacter.h"
#include "Interface/AlienJInteractable.h"


AAlienJBaseInteractableObj::AAlienJBaseInteractableObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ObjMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjMesh"));
	RootComponent = ObjMesh;

	OverlapVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("OverlapVolume"));
	OverlapVolume->SetupAttachment(GetRootComponent());

	// Create and set the widget
	InteractPromptWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractPromtWidget"));
	InteractPromptWidget->SetupAttachment(RootComponent);
	// InteractPromptWidget->SetWidgetClass() // via BP?
	InteractPromptWidget->SetVisibility(false);
}

void AAlienJBaseInteractableObj::BeginPlay()
{
	Super::BeginPlay();

	// Bind overlap callbacks to overlap events
	OverlapVolume->OnComponentBeginOverlap.AddDynamic(this, &AAlienJBaseInteractableObj::OnSphereOverlap);
	OverlapVolume->OnComponentEndOverlap.AddDynamic(this, &AAlienJBaseInteractableObj::OnSphereEndOverlap);
}

void AAlienJBaseInteractableObj::SetInteractWidgetVisibility(bool Visibility)
{
	InteractPromptWidget->SetVisibility(Visibility);
}

void AAlienJBaseInteractableObj::TryInteract(AActor* Interactor)
{
	if (!Interactor) return;
	
	UE_LOG(LogTemp, Warning, TEXT("Test: Interacted with %s"), *Interactor->GetName());
}

void AAlienJBaseInteractableObj::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == GetOwner()) return;
	
	// If OtherActor implements AlienJInteractable, store its reference
	// if (OtherActor->GetClass()->ImplementsInterface(UAlienJInteractable::StaticClass()))
	if (IAlienJInteractable* Interactable = Cast<IAlienJInteractable>(OtherActor))
	{
		UE_LOGFMT(LogTemp, Warning, "Test: Begin overlap, set refs.");
		UE_LOG(LogTemp, Warning, TEXT("OtherComponent: %s"), *OtherComp->GetName());

		/*
		 * TODO: maybe these references aren't needed!
		 *	All it needs it to get the Interactor, check if it's a player and call a "Collected(collectableTag)" method
		 *	that will check the tag and increase the corresponding resource (wood or gold or water etc).
		 * So, this object doesn't need to know about the Interactor nor the Interactor needs a reference to this object if
		 *  it knows what type of resource it represents (that can be done through its tag!).
		 */
		
		// CurrentInteractor = TScriptInterface<IAlienJInteractable>(OtherActor);
		// // Let the interactor know about the interactable obj
		// CurrentInteractor->SetCurrentInteractable(this);

		// Show widget only if it's a player character!
		// Show a widget to indicate it can be interacted with by pressing E.
		// Only after pressing E, it should add to the player or do whatever it needs.
		if (AAlienJCharacter* PlayerCharacter = Cast<AAlienJCharacter>(Interactable))
		{
			SetInteractWidgetVisibility(true);
			PlayerCharacter->SetCurrentInteractableObj(this);
		}
	}
}

void AAlienJBaseInteractableObj::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor || OtherActor == GetOwner()) return;
	
	if (IAlienJInteractable* Interactable = Cast<IAlienJInteractable>(OtherActor))
	{
		if (AAlienJCharacter* PlayerCharacter = Cast<AAlienJCharacter>(Interactable))
		{
			SetInteractWidgetVisibility(false);
			PlayerCharacter->SetCurrentInteractableObj(nullptr);
            UE_LOGFMT(LogTemp, Warning, "Test: End overlap, set widget visibility to false. Set ref to nullptr.");
		}
		
		// // Only clear reference if the actor leaving is the same as the stored one
		// if (CurrentInteractor && OtherActor == CurrentInteractor.GetObject())
		// {
		// 	// AAlienJCharacter* Player = Cast<AAlienJCharacter>(CurrentInteractor.GetObject());
		// 	// if (Player && Player->InteractPromptWidget)
		// 	// {
		// 	// 	Player->SetInteractWidgetVisibility(false);
		// 	// 	UE_LOGFMT(LogTemp, Warning, "Test: End overlap, set widget visibility to false");
		// 	// }
		//
		// 	// Set references to nullptr - both the Interactor and Interactable
		// 	CurrentInteractor->SetCurrentInteractable(nullptr);	
		// 	CurrentInteractor = nullptr;
		// 	UE_LOGFMT(LogTemp, Warning, "Test: End overlap, set refs to null");
		// }
	}
}

void AAlienJBaseInteractableObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
