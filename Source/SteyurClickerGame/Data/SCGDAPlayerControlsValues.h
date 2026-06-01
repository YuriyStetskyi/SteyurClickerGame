// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SCGDAPlayerControlsValues.generated.h"

/**
 * 
 */
UCLASS()
class STEYURCLICKERGAME_API USCGDAPlayerControlsValues : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, Category = "Movement")
    int32 StartingFlySpeed;

    UPROPERTY(EditAnywhere, Category = "Movement")
    int32 MinFlySpeed;

    UPROPERTY(EditAnywhere, Category = "Movement")
    int32 MaxFlySpeed;

    /* Number by which Fly speed will be modified Fly Speed modification input is pressed */
    UPROPERTY(EditAnywhere, Category = "Movement")
    int32 FlySpeedModificationInterval;

    /* Value at which Acceleration changes compared to Fly Speed */
    UPROPERTY(EditAnywhere, Category = "Movement|Unreal Values Modifier")
    int32 MaxAccelerationModifier;

    /* Value at which BreakingDeceleration changes compared to Fly Speed */
    UPROPERTY(EditAnywhere, Category = "Movement|Unreal Values Modifier")
    int32 BreakingDecelerationModifier;

    /*
        You dont want Minimum Breaking Deceleration to be 0
        It might cause camera to almost never stop moving at low speeds
    */
    UPROPERTY(EditAnywhere, Category = "Movement|Unreal Values Modifier")
    int32 MinBreakingDeceleration;

    /*
        Might ass well set it to a billion millions
    */
    UPROPERTY(EditAnywhere, Category = "Movement|Unreal Values Modifier")
    int32 MaxBreakingDeceleration;
};
