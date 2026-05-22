// Fill out your copyright notice in the Description page of Project Settings.


#include "Sofa.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "ShowcaseMenu.h"
#include "ObjectCustomizationMenu.h"

// Sets default values
ASofa::ASofa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	SofaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SofaMesh"));
	SofaCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("SofaCollision"));

	SofaCollision->OnComponentBeginOverlap.AddDynamic(this, &ASofa::OnOverlapBegin);


}

// Called when the game starts or when spawned
void ASofa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASofa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASofa::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this))
	{
		ACharacter* TouchedPlayer = Cast<ACharacter>(OtherActor);

		if (TouchedPlayer)
		{
		
			UE_LOG(LogTemp, Warning, TEXT("Character %s stepped into the Sofa zone!"), *TouchedPlayer->GetName());

			// Logic to open menu or highlight cabinet goes here
		}
	}
}