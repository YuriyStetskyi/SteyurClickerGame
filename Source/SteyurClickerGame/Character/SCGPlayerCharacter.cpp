// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Character/SCGPlayerCharacter.h"
#include "Core/SCGPlayerState.h"
#include "Controller/SCGPlayerController.h"
#include "UI/HUD/SCGHUD.h"

// Sets default values
ASCGPlayerCharacter::ASCGPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASCGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCGPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    InitializeOverlay();
}

// Called every frame
void ASCGPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASCGPlayerCharacter::InitializeOverlay()
{
    ASCGPlayerState* const PS = GetPlayerState<ASCGPlayerState>();
    if (!PS) return;

    ASCGPlayerController* const PC = Cast<ASCGPlayerController>(GetController());
    if (!PC) return;

    ASCGHUD* const HUD = Cast<ASCGHUD>(PC->GetHUD());

    HUD->InitOverlay(PC, PS);
}

