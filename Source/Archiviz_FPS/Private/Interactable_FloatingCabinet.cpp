// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable_FloatingCabinet.h"
#include "Components/StaticMeshComponent.h"

AInteractable_FloatingCabinet::AInteractable_FloatingCabinet()
{

	int32 NoOfMeshes = 8;
	for (int32 i = 0; i <= NoOfMeshes; i++)
	{
		FName MeshName = *FString::Printf(TEXT("PreviewMesh_%d"), i);
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArrayofMeshComponent")
		PreviewMesh = CreateDefaultSubobject<UStaticMeshComponent>(MeshName);

		if (PreviewMesh)
		{
			MeshArray.Add(PreviewMesh);
		}
	}
}


