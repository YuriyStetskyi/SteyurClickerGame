// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SCGResourceComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnResourceSetDelegate, int32);
DECLARE_MULTICAST_DELEGATE(FOnResourceDepletedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEYURCLICKERGAME_API USCGResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USCGResourceComponent();

    UFUNCTION(BlueprintCallable)
    void SetResource(const int32 NewResource);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditDefaultsOnly, Category = "Config")
    int32 MaxResource;

    UPROPERTY(EditDefaultsOnly, Category = "Config")
    int32 Resource;

    FOnResourceSetDelegate OnResourceSet;

    FOnResourceDepletedDelegate OnResourceDepleted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
