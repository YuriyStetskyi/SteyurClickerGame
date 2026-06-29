// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "UI/WidgetController/SCGWidgetController.h"

FWidgetControllerParams::FWidgetControllerParams()
    : PlayerController(nullptr)
    , PlayerState(nullptr)
    , OwningActor(nullptr)
{
}

FWidgetControllerParams::FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS, AActor* const OA)
    : PlayerController(PC)
    , PlayerState(PS)
    , OwningActor(OA)
{
}

void USCGWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    OwningActor = WCParams.OwningActor;
}

void USCGWidgetController::BroadcastInitialValues()
{

}

void USCGWidgetController::BindCallbacksToDependencies()
{

}
