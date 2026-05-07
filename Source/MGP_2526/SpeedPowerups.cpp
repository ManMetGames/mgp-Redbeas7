// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerups.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

SpeedPowerups::SpeedPowerups()
{
	BoostedSpeed = 1000.0f;//speed boost while powerup is active
		OriginalSpeed = 0.0f;
}

void SpeedPowerups::ApplyPowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
		// saves the original walk speed to revert to after duration ends
		OriginalSpeed = TargetCharacter->GetCharacterMovement()->MaxWalkSpeed;

		//applys the new speed to the player
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = BoostedSpeed;
}

void SpeedPowerups::RemovePowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
		//reverts to normal speed
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = OriginalSpeed;

	//calls parent to destroy the powerup
	Super::RemovePowerupEffect();
}
