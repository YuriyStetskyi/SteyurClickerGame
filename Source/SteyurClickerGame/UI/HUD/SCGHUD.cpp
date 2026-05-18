// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "UI/HUD/SCGHUD.h"
#include "UI/WidgetController/SCGWidgetController.h"
#include "UI/Widget/SCGUserWidget.h"
#include "UI/WidgetController/SCGOverlayWidgetController.h"

void ASCGHUD::InitOverlay(APlayerController* const PC, APlayerState* const PS)
{
    UWorld* const CurrentWorld = GetWorld();
    if (!CurrentWorld) return;

    UUserWidget* const Widget = CreateWidget<UUserWidget>(CurrentWorld, OverlayWidgetClass);
    if (!Widget) return;

    OverlayWidget = Cast<USCGUserWidget>(Widget);
    if (!OverlayWidget) return;

    const FWidgetControllerParams WidgetControllerParams(PC, PS);
    USCGOverlayWidgetController* const WidgetController = GetOverlayWidgetController(WidgetControllerParams);

    OverlayWidget->SetWidgetController(WidgetController);
    WidgetController->BroadcastInitialValues();

    OverlayWidget->AddToViewport();
}

USCGOverlayWidgetController* ASCGHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (!OverlayWidgetController)
    {
        OverlayWidgetController = NewObject<USCGOverlayWidgetController>(this, OverlayWidgetControllerClass);
        OverlayWidgetController->SetWidgetControllerParams(WCParams);
        OverlayWidgetController->BindCallbacksToDependencies();
    }

    return OverlayWidgetController;
}
