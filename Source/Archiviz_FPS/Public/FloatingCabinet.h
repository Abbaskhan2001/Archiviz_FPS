// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FloatingCabinet.generated.h"

UCLASS()
class ARCHIVIZ_FPS_API AFloatingCabinet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingCabinet();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshComponents")
	TArray<UStaticMeshComponent*> CabinetMeshes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshComponents")
	class UStaticMeshComponent* CabinetMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box")
	class UBoxComponent* CabinetCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Menu")
	class UShowcaseMenu* Menu;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
