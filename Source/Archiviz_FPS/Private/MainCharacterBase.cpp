#include "MainCharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/CapsuleComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "InteractableObjectBase.h"

AMainCharacterBase::AMainCharacterBase()
{
    PrimaryActorTick.bCanEverTick = true;

    GetCapsuleComponent()->InitCapsuleSize(45.f, 96.0f);

    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
    FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
    FirstPersonCameraComponent->bUsePawnControlRotation = true;

    Params.AddIgnoredActor(this);

    LineTraceStart = GetActorLocation();
    LineTraceEnd = LineTraceStart + (GetActorForwardVector() * 1000.f);

    WidgetInteract = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteract"));
    WidgetInteract->SetupAttachment(FirstPersonCameraComponent);
    WidgetInteract->InteractionDistance = 500.f;
}

void AMainCharacterBase::BeginPlay()
{
    Super::BeginPlay();
}

void AMainCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacterBase::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacterBase::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &AMainCharacterBase::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacterBase::LookUp);

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacterBase::Interact);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AMainCharacterBase::MoveForward(float Val)
{
    if (Val != 0.0f)
        AddMovementInput(GetActorForwardVector(), Val);
}

void AMainCharacterBase::MoveRight(float Val)
{
    if (Val != 0.0f)
        AddMovementInput(GetActorRightVector(), Val);
}

void AMainCharacterBase::Turn(float Val)
{
    AddControllerYawInput(Val);
}

void AMainCharacterBase::LookUp(float Val)
{
    AddControllerPitchInput(Val);
}

void AMainCharacterBase::InteractPressed()
{
    if (WidgetInteract)
        WidgetInteract->PressPointerKey(EKeys::LeftMouseButton);
}

void AMainCharacterBase::InteractReleased()
{
    if (WidgetInteract)
        WidgetInteract->ReleasePointerKey(EKeys::LeftMouseButton);
}

void AMainCharacterBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    LineTraceStart = FirstPersonCameraComponent->GetComponentLocation();
    LineTraceEnd = LineTraceStart + (FirstPersonCameraComponent->GetForwardVector() * 1000.f);

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult, LineTraceStart, LineTraceEnd, ECC_GameTraceChannel1, Params
    );

    DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd,
        bHit ? FColor::Green : FColor::Red, false, -1.f, 0, 1.f);

    AInteractableObjectBase* NewTarget = nullptr;
    if (bHit && HitResult.GetActor())
    {
        NewTarget = Cast<AInteractableObjectBase>(HitResult.GetActor());
        // If we hit something but it's NOT a picture frame, NewTarget stays nullptr
        // This is correct behavior — keep it
    }

    if (NewTarget != TargetObject)
    {
        TargetObject = NewTarget;

        if (TargetObject)
        {
            UE_LOG(LogTemp, Warning, TEXT("Show — target: %s"), *TargetObject->GetName());
            OnShowPrompt.Broadcast();
            bIsLookingAtObject = true;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Hide — no target"));
            OnHidePrompt.Broadcast();
            bIsLookingAtObject = false;
        }
    }

    
}

void AMainCharacterBase::Interact()
{
    if (bIsLookingAtObject) {
        OnInteract.Broadcast();
    }
}