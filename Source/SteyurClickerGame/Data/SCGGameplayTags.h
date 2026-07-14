// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * Singleton containing native Gameplay Tags
 */

struct FSCGGameplayTags
{
public:
    /* Singleton Getter, Returns single instance of this class. */
    static const FSCGGameplayTags& Get() { return GameplayTags; }

    /* Runs early and initializes gameplay tags. */
    static void InitializeNativeGameplayTags();

    /*
    *   Character Attributes
    */

    FGameplayTag Resource_Gatherable_Ore_Iron;
    FGameplayTag Resource_Gatherable_Ore_Gold;
    FGameplayTag Resource_Gatherable_Ore_Diamonds;

private:
    /* Singleton instance. */
    static FSCGGameplayTags GameplayTags;

};