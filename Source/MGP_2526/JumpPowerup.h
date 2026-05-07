// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerupBases.h" 
#include "JumpPowerup.generated.h"

UCLASS()
class MGP_2526_API AJumpPowerup : public APowerupBases
{
	GENERATED_BODY()

public:
	AJumpPowerup();

protected:
	virtual void ApplyPowerupEffect() override;
	virtual void RemovePowerupEffect() override;

	UPROPERTY(EditAnywhere, Category = "Powerup Settings")
	float BoostedJumpZ;

	float OriginalJumpZ;
};