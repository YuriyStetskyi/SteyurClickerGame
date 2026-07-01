// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SCGWidgetController.h"
#include "SCGWCResourceBar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResourceSetUIDelegate, float, NewResource);

/**
 *  Widget Controller for Resource Bar Widget tied to Resource Component
 */
UCLASS()
class STEYURCLICKERGAME_API USCGWCResourceBar : public USCGWidgetController
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintAssignable)
    FOnResourceSetUIDelegate OnResourceSet;

    virtual void BroadcastInitialValues() override;

    virtual void BindCallbacksToDependencies() override;
};
