#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacterBase.generated.h"  // MUST be last include, before DECLARE macros

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowPrompt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHidePrompt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);
class UCameraComponent;
class UWidgetInteractionComponent;
class UPhysicsHandleComponent;
class APictureFrames;

UCLASS()
class ARCHIVIZ_FPS_API AMainCharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AMainCharacterBase();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
        UCameraComponent* FirstPersonCameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
        UWidgetInteractionComponent* WidgetInteract;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PhysicsHandle")
        UPhysicsHandleComponent* ObjectGrabber;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnShowPrompt OnShowPrompt;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnHidePrompt OnHidePrompt;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnInteract OnInteract;

    bool bIsLookingAtObject = false;
    bool bIsLookingAtPic = false;

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

    void MoveForward(float Val);
    void MoveRight(float Val);
    void Turn(float Val);
    void LookUp(float Val);
    void InteractPressed();
    void InteractReleased();
    void Interact();

    FVector LineTraceStart;
    FVector LineTraceEnd;
    FHitResult HitResult;
    FCollisionQueryParams Params;

    APictureFrames* TargetPictureFrame = nullptr;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};