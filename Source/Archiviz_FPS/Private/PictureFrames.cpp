// Fill out your copyright notice in the Description page of Project Settings.


#include "PictureFrames.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MainCharacterBase.h"

// Sets default values
APictureFrames::APictureFrames()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	MeshCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

	Mesh->SetupAttachment(RootComponent);
	MeshCollision->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void APictureFrames::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter->OnInteract.AddDynamic(this, &APictureFrames::ChangeMesh);
	
}

// Called every frame
void APictureFrames::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APictureFrames::ChangeMesh()
{
	
}

