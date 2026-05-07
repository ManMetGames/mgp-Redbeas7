// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CoreMinimal.h"
#include "PowerupBases.h" 
#include "SpeedPowerups.generated.h"

UCLASS()
class MGP_2526_API ASpeedPowerups : public APowerupBases
{
	GENERATED_BODY()

public:
	ASpeedPowerups(); 

protected:
	virtual void ApplyPowerupEffect() override;
	virtual void RemovePowerupEffect() override;

	UPROPERTY(EditAnywhere, Category = "Powerup Settings")
	float BoostedSpeed;

	float OriginalSpeed;
};