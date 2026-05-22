// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interaction_Prompt.generated.h"

/**
 * 
 */


UCLASS()
class ARCHIVIZ_FPS_API UInteraction_Prompt : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	class UButton* InteractionButton;

	
};
