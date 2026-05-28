// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Controller/SCGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Character/SCGPlayerCharacter.h"
#include "EnhancedInputComponent.h"

void ASCGPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

    SetupEnhancedInput();
    SetupInputActions(aPawn);
}

void ASCGPlayerController::SetupEnhancedInput()
{
    if (!IsLocalController() || !DefaultMappingContext) return;

    ULocalPlayer* const LocalPlayer = GetLocalPlayer();
    if (!LocalPlayer) return;

    UEnhancedInputLocalPlayerSubsystem* const InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
    if (!InputSubsystem) return;

    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(DefaultMappingContext, InputPriority);
}

void ASCGPlayerController::SetupInputActions(APawn* const ControlledPawn)
{
    ASCGPlayerCharacter* const PlayerCharacter = Cast<ASCGPlayerCharacter>(ControlledPawn);
    if (!PlayerCharacter) return;

    UEnhancedInputComponent* const EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    if (!EnhancedInputComponent) return;

    EnhancedInputComponent->bind
}
