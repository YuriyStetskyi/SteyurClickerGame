// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "UI/WidgetController/SCGWCResourceBar.h"
#include "Components/SCGResourceComponent.h"

void USCGWCResourceBar::BroadcastInitialValues()
{
    USCGResourceComponent* const ResourceComponent = OwningActor->GetComponentByClass<USCGResourceComponent>();
    if (!ResourceComponent) return;

    OnResourceSet.Broadcast(ResourceComponent->Resource);
}

void USCGWCResourceBar::BindCallbacksToDependencies()
{
    USCGResourceComponent* const ResourceComponent = OwningActor->GetComponentByClass<USCGResourceComponent>();
    if (!ResourceComponent) return;

    ResourceComponent->OnResourceSet.AddLambda([this](int32 NewResource) 
        {
            OnResourceSet.Broadcast(NewResource);
        });
}
