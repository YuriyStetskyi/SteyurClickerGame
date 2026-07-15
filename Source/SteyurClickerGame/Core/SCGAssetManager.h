// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SCGAssetManager.generated.h"

/**
 * Class that loads assets at a proper moment in programs lifetime. Currently only loads Native GameplayTags.
 */
UCLASS()
class STEYURCLICKERGAME_API USCGAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
    /* Gets Asset Manager instance. */
    static USCGAssetManager& Get();

protected:
    /* Main function that is used to load initial data of asset manager. */
    virtual void StartInitialLoading() override;
};
