// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerups.h" 
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

ASpeedPowerups::ASpeedPowerups()
{
	BoostedSpeed = 1000.f;
	OriginalSpeed = 0.f;
}

void ASpeedPowerups::ApplyPowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		OriginalSpeed = TargetCharacter->GetCharacterMovement()->MaxWalkSpeed;
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = BoostedSpeed;
	}
}

void ASpeedPowerups::RemovePowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		TargetCharacter->GetCharacterMovement()->MaxWalkSpeed = OriginalSpeed;
	}

	Super::RemovePowerupEffect();
}