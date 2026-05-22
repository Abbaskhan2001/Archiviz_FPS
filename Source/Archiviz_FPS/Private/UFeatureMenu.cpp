#include "UFeatureMenu.h"
#include "Components/Button.h"  // full include goes in .cpp only

void UUFeatureMenu::NativeConstruct()
{
    Super::NativeConstruct();

    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &UUFeatureMenu::OnCloseButtonClicked);
    }

    if (Selection1)
    {
        Selection1->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject1);
    }
    if (Selection2)
    {
        Selection2->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject2);
    }
    if (Selection3)
    {
        Selection3->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject3);
    }
    if (Selection4)
    {
        Selection4->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject4);
    }
    if (Selection5)
    {
        Selection5->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject5);
    }
    if (Selection6)
    {
        Selection6->OnClicked.AddDynamic(this, &UUFeatureMenu::SelectObject6);
    }

}

void UUFeatureMenu::OnCloseButtonClicked()
{
    OnMenuClosed.Broadcast();
}
void UUFeatureMenu::SelectObject1()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject1 called"));

    if (!ActorClass1)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass1 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass1->GetName());
    SpawnObject.Broadcast(ActorClass1);
}

void UUFeatureMenu::SelectObject2()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject2 called"));

    if (!ActorClass2)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass2 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass2->GetName());
    SpawnObject.Broadcast(ActorClass2);
}
void UUFeatureMenu::SelectObject3()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject3 called"));

    if (!ActorClass3)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass3 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass3->GetName());
    SpawnObject.Broadcast(ActorClass2);
}

void UUFeatureMenu::SelectObject4()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject2 called"));

    if (!ActorClass4)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass4 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass4->GetName());
    SpawnObject.Broadcast(ActorClass4);
}

void UUFeatureMenu::SelectObject5()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject5 called"));

    if (!ActorClass5)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass5 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass5->GetName());
    SpawnObject.Broadcast(ActorClass5);
}

void UUFeatureMenu::SelectObject6()
{
    UE_LOG(LogTemp, Warning, TEXT("SelectObject6 called"));

    if (!ActorClass6)
    {
        UE_LOG(LogTemp, Error, TEXT("ActorClass6 is NULL in widget!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Broadcasting SpawnObject with class: %s"), *ActorClass6->GetName());
    SpawnObject.Broadcast(ActorClass6);
}