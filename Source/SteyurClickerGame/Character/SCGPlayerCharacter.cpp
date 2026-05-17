// // Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins


#include "Character/SCGPlayerCharacter.h"

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

