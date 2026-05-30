// Fill out your copyright notice in the Description page of Project Settings.


#include "Sofa.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "ShowcaseMenu.h"
#include "ObjectCustomizationMenu.h"
#include "MainCharacterBase.h"

// Sets default values
ASofa::ASofa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	SofaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SofaMesh"));
}

// Called when the game starts or when spawned
void ASofa::BeginPlay()

{
	Super::BeginPlay();

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        MyCharacter = Cast<AMainCharacterBase>(PC->GetPawn());
    }

    if (MyCharacter)
    {
        MyCharacter->OnInteract.AddDynamic(this, &ASofa::ChangeMesh);
        UE_LOG(LogTemp, Warning, TEXT("OnInteract bound on: %s"), *GetName());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("MyCharacter is NULL in: %s"), *GetName());
    }
}

// Called every frame
void ASofa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}