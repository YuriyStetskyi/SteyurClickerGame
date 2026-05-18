// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SCGWidgetController.generated.h"

/* 
    Params struct that each Widget controller uses to initialize itself.
    Includes most important classes Widgets might need to access to work properly
*/
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
    GENERATED_BODY()

    FWidgetControllerParams();
    FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS);

    UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
    APlayerState* PlayerState;
};


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class STEYURCLICKERGAME_API USCGWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
    
    /* Allows to set Widget Controller Params if needed at runtime. */
    UFUNCTION(BlueprintCallable)
    void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

    /* 
        Called ONCE when initializing starting values of Widget visible variables.
        Override in inherited class.
    */
    void BroadcastInitialValues();

    /*
        Called ONCE when binding appropriate functions to delegates responsible for
        altering Widget visible variables.
        Override in inherited class.
    */
    void BindCallbacksToDependencies();

protected:

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    APlayerState* PlayerState;
};
