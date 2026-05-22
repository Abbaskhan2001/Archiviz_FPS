#include "ShowcaseMenu.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


UShowcaseMenu::UShowcaseMenu()
{
        this->SetDrawSize(FVector2D(1000.0f, 1000.0f));
        this->SetWidgetClass(UObjectCustomizationMenu::StaticClass());
}
