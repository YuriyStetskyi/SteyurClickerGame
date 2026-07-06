// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCGBaseGatherable.generated.h"

class USCGResourceComponent;

UCLASS()
class STEYURCLICKERGAME_API ASCGBaseGatherable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASCGBaseGatherable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    USCGResourceComponent* Resource;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
