#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UFeatureMenu.h"
#include "Interaction_Prompt.h"
#include "MainCharacterBase.h"
#include "MyPlayerController.generated.h"

UCLASS()
class  ARCHIVIZ_FPS_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AMyPlayerController();
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    // Assign your Widget Blueprint in editor
    UPROPERTY(EditDefaultsOnly, Category = "UI")
        TSubclassOf<UUFeatureMenu> MenuWidgetClass;
    UPROPERTY(EditDefaultsOnly, Category = "UI")
        TSubclassOf<UInteraction_Prompt> Interaction_PromptClass;

    UPROPERTY()
        AMainCharacterBase* MyCharacter;

    virtual void OnPossess(APawn* InPawn) override;
    

private:
    // The actual created widget instance
    UUFeatureMenu* MenuWidget;
    UInteraction_Prompt* Interact_Prompt;

    bool bMenuOpen = false;
    bool bPromptShown = false;

    // Called when Tab is pressed
    UFUNCTION()
        void ShowPrompt();
    UFUNCTION()
        void HidePrompt();


    // Called when widget fires OnMenuClosed delegate
    UFUNCTION()
        void HandleMenuClosed();

    // Shared helper functions
    void OpenMenu();
    void CloseMenu();
    UFUNCTION()
    void OnSpawnActor(TSubclassOf<AActor> SelectedItem);
};