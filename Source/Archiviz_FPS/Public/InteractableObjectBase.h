// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObjectBase.generated.h"

UCLASS()
class ARCHIVIZ_FPS_API AInteractableObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableObjectBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PreviewMeshComponent")
		class UStaticMeshComponent* PreviewMesh;
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
