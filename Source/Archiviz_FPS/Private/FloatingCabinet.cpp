// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingCabinet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "ShowcaseMenu.h"

// Sets default values
AFloatingCabinet::AFloatingCabinet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Menu = CreateDefaultSubobject<UShowcaseMenu>(TEXT("Menu"));
	CabinetCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CabinetCollision"));
	CabinetCollision->OnComponentBeginOverlap.AddDynamic(this, &AFloatingCabinet::OnOverlapBegin);
	Menu->SetupAttachment(RootComponent);
	Menu->SetVisibility(false);
	CabinetCollision->SetupAttachment(RootComponent);
	int32 NoOfMeshes = 8;
	

	for (int32 i=0;i<=NoOfMeshes;i++)
	{
		FName MeshName = *FString::Printf(TEXT("CabinetMesh_%d"), i);
		CabinetMesh = CreateDefaultSubobject<UStaticMeshComponent>(MeshName);
		
		if (CabinetMesh)
		{
			CabinetMeshes.Add(CabinetMesh);
		}
	}


}

// Called when the game starts or when spawned
void AFloatingCabinet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingCabinet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloatingCabinet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this))
	{
		ACharacter* TouchedPlayer = Cast<ACharacter>(OtherActor);
		
		if (TouchedPlayer)
		{
			Menu->SetVisibility(true);
			UE_LOG(LogTemp, Warning, TEXT("Character %s stepped into the cabinet zone!"), *TouchedPlayer->GetName());

			
		}
	}
}

