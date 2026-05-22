#include "Table.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

ATable::ATable()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    TableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TableMesh"));
    TableMesh->SetupAttachment(RootComponent);

    TableCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("TableCollision"));
    TableCollision->SetupAttachment(RootComponent);
    TableCollision->OnComponentBeginOverlap.AddDynamic(this, &ATable::OnOverlapBegin);
}

void ATable::BeginPlay()
{


}

void ATable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && (OtherActor != this))
    {
        ACharacter* TouchedPlayer = Cast<ACharacter>(OtherActor);
        if (TouchedPlayer)
        {
            UE_LOG(LogTemp, Warning, TEXT("Character stepped close to the table. Showing 3D menu."));

           
        }
    }
}