// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Components/SCGResourceComponent.h"

// Sets default values for this component's properties
USCGResourceComponent::USCGResourceComponent()
    : MaxResource(100)
    , Resource(MaxResource)
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void USCGResourceComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USCGResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USCGResourceComponent::SetResource(const int32 NewResource)
{
    int32 ClampedResource = FMath::Clamp(NewResource, 0, MaxResource);

    Resource = ClampedResource;
    OnResourceSet.Broadcast(ClampedResource);

    if (Resource == 0) OnResourceDepleted.Broadcast();
}

