// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SCGWidgetController.generated.h"

/* 
    Params struct that each Widget controller uses to initialize itself.
    Includes most important classes Widgets might need to access to work properly
*/
USTRUCT(BlueprintType, Blueprintable)
struct FWidgetControllerParams
{
    GENERATED_BODY()

    FWidgetControllerParams();
    FWidgetControllerParams(APlayerController* const PC, APlayerState* const PS, AActor* const OA);

    UPROPERTY(BlueprintReadWrite, Category = "Widget Controller")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadWrite, Category = "Widget Controller")
    APlayerState* PlayerState;

    UPROPERTY(BlueprintReadWrite, Category = "Widget Controller")
    AActor* OwningActor;
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
    UFUNCTION(BlueprintCallable)
    virtual void BroadcastInitialValues();

    /*
        Called ONCE when binding appropriate functions to delegates responsible for
        altering Widget visible variables.
        Override in inherited class.
    */
    UFUNCTION(BlueprintCallable)
    virtual void BindCallbacksToDependencies();

    UPROPERTY(BlueprintReadWrite, Category = "WidgetController")
    APlayerController* PlayerController;

    UPROPERTY(BlueprintReadWrite, Category = "WidgetController")
    APlayerState* PlayerState;

    UPROPERTY(BlueprintReadWrite, Category = "WidgetController")
    AActor* OwningActor;
};
