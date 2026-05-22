// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectCustomizationMenu.h"
#include "Components/Button.h"

void UObjectCustomizationMenu::NativeConstruct()
{
    Super::NativeConstruct();

    if (Version1)
    {
        Version1->OnClicked.AddDynamic(this, &UObjectCustomizationMenu::SelectVersion1);

    }
    if (Version2)
    {
        Version2->OnClicked.AddDynamic(this, &UObjectCustomizationMenu::SelectVersion2);
    }
    if (Version3)
    {
        Version3->OnClicked.AddDynamic(this, &UObjectCustomizationMenu::SelectVersion3);
    }
}

void UObjectCustomizationMenu::SelectVersion1()
{
    OnSelect.Broadcast();
    UE_LOG(LogTemp, Error, TEXT("Version1 Material Selected"));
}
void UObjectCustomizationMenu::SelectVersion2()
{
    OnSelect.Broadcast();
    UE_LOG(LogTemp, Error, TEXT("Version1 Material Selected"));
}
void UObjectCustomizationMenu::SelectVersion3()
{
    OnSelect.Broadcast();
    UE_LOG(LogTemp, Error, TEXT("Version1 Material Selected"));
}
