// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "UI/WidgetController/SCGWidgetController.h"

FWidgetControllerParams::FWidgetControllerParams()
    : PlayerController(nullptr)
    , PlayerState(nullptr)
{
}

FWidgetControllerParams::FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS)
    : PlayerController(PC)
    , PlayerState(PS)
{
}

void USCGWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
}

void USCGWidgetController::BroadcastInitialValues()
{
}

void USCGWidgetController::BindCallbacksToDependencies()
{
}
