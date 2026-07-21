// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Interface/SCGInteractable.h"
#include "GameplayTagAssetInterface.h"
#include "SCGBaseGatherable.generated.h"

class USCGResourceComponent;

UCLASS()
class STEYURCLICKERGAME_API ASCGBaseGatherable : public AActor, public IGameplayTagAssetInterface, public ISCGInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASCGBaseGatherable();

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    USCGResourceComponent* Resource;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
    FGameplayTagContainer GameplayTags;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    virtual bool Interact(AActor* InteractionActor);
};
