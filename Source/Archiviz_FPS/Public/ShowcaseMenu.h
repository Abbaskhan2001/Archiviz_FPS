// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ObjectCustomizationMenu.h"
#include "ShowcaseMenu.generated.h"

/**
 * 
 */
UCLASS()
class ARCHIVIZ_FPS_API UShowcaseMenu : public UWidgetComponent
{
    GENERATED_BODY()
public:
    UShowcaseMenu();  // declaration only, no curly braces
    UPROPERTY()
        UObjectCustomizationMenu* ObjectMenu;
protected:
};
