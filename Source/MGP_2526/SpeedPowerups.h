// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerupBases.h" //Inherits from the base class
#include "SpeedPowerups.generated.h"
/**
 * 
 */
class MGP_2526_API SpeedPowerups : public APowerupBases
{
	GENERATED_BODY()
public:
	SpeedPowerups();

protected:
	virtual void ApplyPowerupEffect();
	virtual void RemovePowerupEffect();

	UPROPERTY(EditAnywhere, Category = "Powerup Settings")
	float BoostedSpeed;
	float OriginalSpeed;
};
