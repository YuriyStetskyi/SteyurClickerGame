// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Data/SCGGameplayTags.h"
#include "GameplayTagsManager.h"

FSCGGameplayTags FSCGGameplayTags::GameplayTags;

void FSCGGameplayTags::InitializeNativeGameplayTags()
{
    // Initializing Character Attribute Tags

    GameplayTags.Resource_Gatherable_Ore_Iron = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resource.Gathertable.Ore.Iron"), FString("Gatherable resource Iron. Common Resource"));
    GameplayTags.Resource_Gatherable_Ore_Gold = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resource.Gathertable.Ore.Gold"), FString("Gatherable resource Gold. Uncommon Resource"));
    GameplayTags.Resource_Gatherable_Ore_Diamonds = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Resource.Gathertable.Ore.Diamonds"), FString("Gatherable resource Diamonds. Rare Resource"));
}
