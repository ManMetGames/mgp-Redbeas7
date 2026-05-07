// Fill out your copyright notice in the Description page of Project Settings.

#include "JumpPowerup.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AJumpPowerup::AJumpPowerup()
{
	BoostedJumpZ = 1200.f;
	OriginalJumpZ = 0.f;
}

void AJumpPowerup::ApplyPowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		OriginalJumpZ = TargetCharacter->GetCharacterMovement()->JumpZVelocity;
		TargetCharacter->GetCharacterMovement()->JumpZVelocity = BoostedJumpZ;
	}
}

void AJumpPowerup::RemovePowerupEffect()
{
	if (TargetCharacter && TargetCharacter->GetCharacterMovement())
	{
		TargetCharacter->GetCharacterMovement()->JumpZVelocity = OriginalJumpZ;
	}

	Super::RemovePowerupEffect();
}