// Copyright (c) 2025 Yuriy "Steyur" Stetskyi - MIT License. Strategy Clicker Goblins

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/SCGBaseCharacter.h"
#include "SCGPlayerCharacter.generated.h"

class UCameraComponent;
class UCapsuleComponent;
class USCGDAPlayerControlsValues;
class ASCGPlayerController;

struct FInputActionValue;

UCLASS()
class STEYURCLICKERGAME_API ASCGPlayerCharacter : public ASCGBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCGPlayerCharacter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void HorizontalMovement(const FInputActionValue& InputActionValue);
    void VerticalMovement(const FInputActionValue& InputActionValue);
    void CameraMovement(const FInputActionValue& InputActionValue);
    void ChangeMovementSpeed(const FInputActionValue& InputActionValue);
    void ToggleFreeCam(const FInputActionValue& InputActionValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void PossessedBy(AController* NewController) override;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Data")
    USCGDAPlayerControlsValues* PlayerControlsData;

    UPROPERTY(EditDefaultsOnly, Category = "Miscellaneous")
    FName DefaultCameraLocationTag;

private:

    /* Initializes game overlay including adding widgets to screen */
    void InitializeOverlay();

    /* Update Acceleration, Deceleration, Fly speed etc.*/
    void UpdateFlyingProperties();

    void SetupMovement();

    /* Helper functions */

    void TeleportCameraToDefaultSpot(ASCGPlayerController* const PlayerController);

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    int32 CurrentFlySpeed;
};
