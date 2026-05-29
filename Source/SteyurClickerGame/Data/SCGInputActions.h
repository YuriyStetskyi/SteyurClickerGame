// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SCGInputActions.generated.h"

class UInputAction;

/**
 * 
 */
UCLASS()
class STEYURCLICKERGAME_API USCGInputActions : public UDataAsset
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Input Actions")
    UInputAction* HorizontalMovement;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    UInputAction* VerticalMovement;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    UInputAction* CameraMovement;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    UInputAction* ChangeMovementSpeed;
};
