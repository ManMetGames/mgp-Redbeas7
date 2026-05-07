// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerups.h" 
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

// Added the 'A' prefixes here
ASpeedPowerups::ASpeedPowerups()
{
	BoostedSpeed = 1000.f;
	OriginalSpeed = 0.f;
}

// Added the 'A' prefix here
void ASpeedPowerups::ApplyPowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		OriginalSpeed = TargetCharacter->GetCharacterMovement()->MaxWalkSpeed;
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = BoostedSpeed;
	}
}

// Added the 'A' prefix here
void ASpeedPowerups::RemovePowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = OriginalSpeed;
	}

	Super::RemovePowerupEffect();
}