// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Character/SCGPlayerCharacter.h"
#include "Core/SCGPlayerState.h"
#include "Controller/SCGPlayerController.h"
#include "UI/HUD/SCGHUD.h"
#include <InputActionValue.h>
#include "Camera/CameraComponent.h"
#include "Data/SCGDAPlayerControlsValues.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASCGPlayerCharacter::ASCGPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));
    CameraComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

void ASCGPlayerCharacter::HorizontalMovement(const FInputActionValue& InputActionValue)
{
    FVector2D MovementVector = InputActionValue.Get<FVector2d>();

    AddMovementInput(CameraComponent->GetRightVector(), MovementVector.X);
    AddMovementInput(CameraComponent->GetForwardVector(), MovementVector.Y);
}

void ASCGPlayerCharacter::VerticalMovement(const FInputActionValue& InputActionValue)
{
    float VerticalMovementValue = InputActionValue.Get<float>();

    AddMovementInput(CameraComponent->GetUpVector(), VerticalMovementValue);
}

void ASCGPlayerCharacter::CameraMovement(const FInputActionValue& InputActionValue)
{
    FVector2D CameraRotationVector = InputActionValue.Get<FVector2d>();

    AddControllerYawInput(CameraRotationVector.X);
    AddControllerPitchInput(CameraRotationVector.Y);
}

void ASCGPlayerCharacter::ChangeMovementSpeed(const FInputActionValue& InputActionValue)
{
    /* Fly speed = CurrentFlySpeed + (how much changed * Speed Change interval) */
    float SpeedChangeValue = InputActionValue.Get<float>();
    int32 CFlySpeed = CurrentFlySpeed + (SpeedChangeValue * PlayerControlsData->FlySpeedModificationInterval);
    CurrentFlySpeed = FMath::Clamp(CFlySpeed,
        PlayerControlsData->MinFlySpeed,
        PlayerControlsData->MaxFlySpeed);

    UpdateFlyingProperties();
    Tags;
}

// Called when the game starts or when spawned
void ASCGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

    SetupMovement();
}

void ASCGPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    InitializeOverlay();
}

// Called every frame
void ASCGPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASCGPlayerCharacter::InitializeOverlay()
{
    ASCGPlayerState* const PS = GetPlayerState<ASCGPlayerState>();
    if (!PS) return;

    ASCGPlayerController* const PC = Cast<ASCGPlayerController>(GetController());
    if (!PC) return;

    ASCGHUD* const HUD = Cast<ASCGHUD>(PC->GetHUD());

    HUD->InitOverlay(PC, PS);
}

void ASCGPlayerCharacter::UpdateFlyingProperties()
{
    UCharacterMovementComponent* const MovementComponent = GetCharacterMovement();
    if (!MovementComponent) return;

    MovementComponent->MaxAcceleration = CurrentFlySpeed * PlayerControlsData->MaxAccelerationModifier;
    MovementComponent->MaxFlySpeed = CurrentFlySpeed;

    int32 BDFlying = CurrentFlySpeed * PlayerControlsData->BreakingDecelerationModifier;
    MovementComponent->BrakingDecelerationFlying = FMath::Clamp(BDFlying, 
        PlayerControlsData->MinBreakingDeceleration, 
        PlayerControlsData->MaxBreakingDeceleration); 
}

void ASCGPlayerCharacter::SetupMovement()
{
    CurrentFlySpeed = PlayerControlsData->StartingFlySpeed;
    UpdateFlyingProperties(); //once setup on begin play, then called when changed movement speed etc.
}

