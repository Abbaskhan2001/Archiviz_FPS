// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectCustomizationMenu.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelect);

UCLASS()
class ARCHIVIZ_FPS_API UObjectCustomizationMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnSelect OnSelect;

	UPROPERTY(meta = (BindWidget))
	class UButton* Version1;
	UPROPERTY(meta = (BindWidget))
	class UButton* Version2;
	UPROPERTY(meta = (BindWidget))
	class UButton* Version3;

	UFUNCTION()
		void SelectVersion1();
	UFUNCTION()
		void SelectVersion2();
	UFUNCTION()
		void SelectVersion3();

	
};
