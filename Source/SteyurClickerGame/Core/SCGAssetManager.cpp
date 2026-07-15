// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Core/SCGAssetManager.h"
#include "Data/SCGGameplayTags.h"

USCGAssetManager& USCGAssetManager::Get()
{
    check(GEngine);

    USCGAssetManager* const SCGAssetManager = Cast<USCGAssetManager>(GEngine->AssetManager);
    return *SCGAssetManager;
}

void USCGAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    FSCGGameplayTags::InitializeNativeGameplayTags();
}

