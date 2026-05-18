// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCGPlayerCharacter.generated.h"

UCLASS()
class STEYURCLICKERGAME_API ASCGPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCGPlayerCharacter();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void PossessedBy(AController* NewController) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

    /* Initializes game overlay including adding widgets to screen */
    void InitializeOverlay();
};
