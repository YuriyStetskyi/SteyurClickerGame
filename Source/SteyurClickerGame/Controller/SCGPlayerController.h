// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SCGPlayerController.generated.h"

class UInputMappingContext;
class USCGInputActions;
/**
 * 
 */
UCLASS()
class STEYURCLICKERGAME_API ASCGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    UPROPERTY(VisibleDefaultsOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* FreeCamMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* LockedMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    USCGInputActions* InputActions;

protected:
    virtual void OnPossess(APawn* aPawn) override;

private:

    /* Sets up enhanced input ONCE on posession of character */
    void SetupEnhancedInput();

    void SetupInputActions(APawn* const ControlledPawn);
};
