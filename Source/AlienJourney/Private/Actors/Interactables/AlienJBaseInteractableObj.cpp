// Fill out your copyright notice in the Description page of Project Settings.

#include "Interface/AlienJInteractable.h"

#include "Actors/Interactables/AlienJBaseInteractableObj.h"

AAlienJBaseInteractableObj::AAlienJBaseInteractableObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ObjMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjMesh"));
	RootComponent = ObjMesh;

	OverlapVolume = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapVolume"));
	OverlapVolume->SetupAttachment(GetRootComponent());
}

void AAlienJBaseInteractableObj::BeginPlay()
{
	Super::BeginPlay();

	OverlapVolume->OnComponentBeginOverlap.AddDynamic(this, &AAlienJBaseInteractableObj::OnSphereOverlap);
	OverlapVolume->OnComponentEndOverlap.AddDynamic(this, &AAlienJBaseInteractableObj::OnSphereEndOverlap);
	
}

void AAlienJBaseInteractableObj::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAlienJInteractable* InteractableInterface = Cast<IAlienJInteractable>(OtherActor))
	{
		InteractableInterface->SetOverlappingObject(this);

		// Also, show a widget to indicate it can be interacted with by pressing E.
		// Only after pressing E, it should add to the player or do whatever it needs.
	}
}

void AAlienJBaseInteractableObj::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IAlienJInteractable* InteractableInterface = Cast<IAlienJInteractable>(OtherActor))
	{
		InteractableInterface->SetOverlappingObject(nullptr);
	}
}

void AAlienJBaseInteractableObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

