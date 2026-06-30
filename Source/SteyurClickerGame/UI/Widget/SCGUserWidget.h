// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SCGUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class STEYURCLICKERGAME_API USCGUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
    void SetWidgetController(UObject* InWidgetController);

    /* Entry Point for BP logic in each widget */
    UFUNCTION(BlueprintNativeEvent)
    void WidgetControllerSet();

    UPROPERTY(BlueprintReadOnly)
    UObject* WidgetController;
};
