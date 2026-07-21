// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCGInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USCGInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STEYURCLICKERGAME_API ISCGInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

    virtual bool Interact(AActor* InteractionActor) = 0;
};
