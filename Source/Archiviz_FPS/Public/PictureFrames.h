// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PictureFrames.generated.h"



UCLASS()
class ARCHIVIZ_FPS_API APictureFrames : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APictureFrames();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "MeshComponent")
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MeshComponent")
	class UBoxComponent* MeshCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyCharacter")
	class AMainCharacterBase* MyCharacter;

	void ChangeMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
