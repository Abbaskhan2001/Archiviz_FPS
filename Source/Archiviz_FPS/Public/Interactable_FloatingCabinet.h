// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableObjectBase.h"
#include "Interactable_FloatingCabinet.generated.h"

/**
 * 
 */
UCLASS()
class ARCHIVIZ_FPS_API AInteractable_FloatingCabinet : public AInteractableObjectBase
{
	GENERATED_BODY()
public:
	AInteractable_FloatingCabinet();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StaticMeshComponent")
		TArray<UStaticMeshComponent*> MeshArray;
		

};
