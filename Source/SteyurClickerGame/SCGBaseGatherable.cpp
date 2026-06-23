// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "SCGBaseGatherable.h"
#include "Components/SCGResourceComponent.h"

// Sets default values
ASCGBaseGatherable::ASCGBaseGatherable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

    Resource = CreateDefaultSubobject<USCGResourceComponent>(TEXT("Ore Resource"));
}

// Called when the game starts or when spawned
void ASCGBaseGatherable::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void ASCGBaseGatherable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

