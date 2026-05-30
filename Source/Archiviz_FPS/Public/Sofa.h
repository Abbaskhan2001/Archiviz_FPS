// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sofa.generated.h"

UCLASS()
class ARCHIVIZ_FPS_API ASofa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASofa();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="StaticMeshComponent")
	class UStaticMeshComponent* SofaMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyCharacter")
		class AMainCharacterBase* MyCharacter;

	UFUNCTION(BlueprintImplementableEvent, Category = "EVENT")
		void ChangeMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
