// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SCGHUD.generated.h"

struct FWidgetControllerParams;

class USCGUserWidget;
class USCGWidgetController;
class USCGOverlayWidgetController;
/**
 * 
 */
UCLASS()
class STEYURCLICKERGAME_API ASCGHUD : public AHUD
{
	GENERATED_BODY()

public:
    UPROPERTY()
    USCGUserWidget* OverlayWidget;
    
    void InitOverlay(APlayerController* const PC, APlayerState* const PS);

    USCGOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
protected:


private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<USCGUserWidget> OverlayWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<USCGWidgetController> OverlayWidgetControllerClass;

    UPROPERTY()
    USCGOverlayWidgetController* OverlayWidgetController;
};
