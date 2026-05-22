#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UFeatureMenu.generated.h"  // generated.h must ALWAYS be last include

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMenuClosed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnObject, TSubclassOf<AActor>, ActorClass);

UCLASS()
class ARCHIVIZ_FPS_API UUFeatureMenu : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintAssignable, Category = "Events")
        FOnMenuClosed OnMenuClosed;

    UPROPERTY(BlueprintAssignable, Category = "Events")
        FSpawnObject SpawnObject;

    UPROPERTY(meta = (BindWidget))
       class UButton* CloseButton;  // forward declaration, no include needed in .h
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection1;
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection2;
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection3;
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection4;
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection5;
    UPROPERTY(meta = (BindWidget))
        class UButton* Selection6;

    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass1; 
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass2;
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass3;
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass4;
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass5;
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
        TSubclassOf<AActor> ActorClass6;

    UFUNCTION()
        void OnCloseButtonClicked();
    UFUNCTION()
        void SelectObject1();
    UFUNCTION()
        void SelectObject2();
    UFUNCTION()
        void SelectObject3();
    UFUNCTION()
        void SelectObject4();
    UFUNCTION()
        void SelectObject5();
    UFUNCTION()
        void SelectObject6();
};