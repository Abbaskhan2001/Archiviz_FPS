#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h" // Include this for the component
#include "Table.generated.h"

UCLASS()
class ARCHIVIZ_FPS_API ATable : public AActor
{
    GENERATED_BODY()

public:
    ATable();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshComponent")
        class UStaticMeshComponent* TableMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BoxCollision")
        class UBoxComponent* TableCollision;

    UFUNCTION()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
            int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
    virtual void BeginPlay() override;
};