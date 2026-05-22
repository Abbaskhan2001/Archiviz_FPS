#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
    // Initialize pointer to null for safety
    MenuWidget = nullptr;
    Interact_Prompt = nullptr;
    bMenuOpen = false;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay called"));

    if (MenuWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("MenuWidgetClass is set, creating widget"));
        MenuWidget = CreateWidget<UUFeatureMenu>(this, MenuWidgetClass);

        if (MenuWidget)
        {
            UE_LOG(LogTemp, Warning, TEXT("Widget created successfully"));
            MenuWidget->OnMenuClosed.AddDynamic(this, &AMyPlayerController::HandleMenuClosed);
            MenuWidget->SpawnObject.AddDynamic(this, &AMyPlayerController::OnSpawnActor);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Widget creation FAILED"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("MenuWidgetClass is NOT set!"));
    }

    if (Interaction_PromptClass)
    {
        Interact_Prompt = CreateWidget<UInteraction_Prompt>(this, Interaction_PromptClass);
        UE_LOG(LogTemp, Warning, TEXT("InteractionMenuClass Created"));
       
    }
}


void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind Tab key — make sure "ToggleMenu" exists in Project Settings > Input
    /*InputComponent->BindAction("ToggleMenu", IE_Pressed, this, &AMyPlayerController::ToggleMenu);*/
}


void AMyPlayerController::OpenMenu()
{
    MenuWidget->AddToViewport();
    bShowMouseCursor = true;
    SetInputMode(FInputModeGameAndUI());
    bMenuOpen = true;

    UE_LOG(LogTemp, Warning, TEXT("Menu Opened"));
}

void AMyPlayerController::CloseMenu()
{
    MenuWidget->RemoveFromViewport();
    bShowMouseCursor = false;
    SetInputMode(FInputModeGameOnly());
    bMenuOpen = false;

    UE_LOG(LogTemp, Warning, TEXT("Menu Closed"));
}

void AMyPlayerController::HandleMenuClosed()
{
    // Widget fired the delegate — close the menu
    CloseMenu();
}

void AMyPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    // Always unbind delegate on cleanup
    if (MenuWidget)
    {
        MenuWidget->OnMenuClosed.RemoveDynamic(this, &AMyPlayerController::HandleMenuClosed);
        MenuWidget->SpawnObject.RemoveDynamic(this, &AMyPlayerController::OnSpawnActor);
    }
}

void AMyPlayerController::OnSpawnActor(TSubclassOf<AActor> SelectedClass)
{
    UE_LOG(LogTemp, Warning, TEXT("OnSpawnActor called")); // is it even called?

    if (!SelectedClass)
    {
        UE_LOG(LogTemp, Error, TEXT("SelectedClass is NULL — not assigned in editor"));
        return;
    }

    APawn* PlayerPawn = GetPawn();
    if (!PlayerPawn)
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerPawn is NULL"));
        return;
    }

    FVector SpawnLoc = PlayerPawn->GetActorLocation() + PlayerPawn->GetActorForwardVector() * 200.f;
    FRotator SpawnRot = PlayerPawn->GetActorRotation();

    AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SelectedClass, SpawnLoc, SpawnRot);

    if (SpawnedActor)
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor Spawned Successfully: %s"), *SpawnedActor->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnActor FAILED"));
    }
}


void AMyPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    MyCharacter = Cast<AMainCharacterBase>(InPawn);
    if (MyCharacter)
    {
        MyCharacter->OnShowPrompt.AddDynamic(this, &AMyPlayerController::ShowPrompt);
        MyCharacter->OnHidePrompt.AddDynamic(this, &AMyPlayerController::HidePrompt);
        UE_LOG(LogTemp, Warning, TEXT("OnShowPrompt delegate bound"));
        UE_LOG(LogTemp, Warning, TEXT("OnHidePrompt delegate bound"));
    }
    else
    {
        
        UE_LOG(LogTemp, Error, TEXT("Cast to AMyCharacter failed"));
    }
}

void AMyPlayerController::ShowPrompt()
{
    if (!Interact_Prompt) return;
    if (!Interact_Prompt->IsInViewport())  // guard against double-add
        Interact_Prompt->AddToViewport(1);
}

void AMyPlayerController::HidePrompt()
{
    if (!Interact_Prompt) return;
    if (Interact_Prompt->IsInViewport())   // guard against double-remove
        Interact_Prompt->RemoveFromViewport();
}