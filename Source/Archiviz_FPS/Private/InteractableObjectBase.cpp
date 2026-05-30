// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableObjectBase.h"
#include "MainCharacterBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AInteractableObjectBase::AInteractableObjectBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));/*
	PreviewMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PreviewStaticMeshComponent"));
	PreviewMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AInteractableObjectBase::BeginPlay()
{
	Super::BeginPlay();
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        MyCharacter = Cast<AMainCharacterBase>(PC->GetPawn());
    }

    if (MyCharacter)
    {
        MyCharacter->OnInteract.AddDynamic(this, &AInteractableObjectBase::ChangeMesh);
        UE_LOG(LogTemp, Warning, TEXT("OnInteract bound on: %s"), *GetName());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("MyCharacter is NULL in: %s"), *GetName());
    }
	
}

// Called every frame
void AInteractableObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

