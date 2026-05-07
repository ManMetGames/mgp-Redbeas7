// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerupBases.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class ACharacter;

UCLASS()
class MGP_2526_API APowerupBases : public AActor
{
	GENERATED_BODY()

public:
	APowerupBases();

protected:
	// The collision sphere that detects the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* CollisionSphere;

	// The visual representation of the powerup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// How long the powerup lasts
	UPROPERTY(EditAnywhere, Category = "Powerup Settings")
	float PowerupDuration;

	// The character that picked this up
	ACharacter* TargetCharacter;

	FTimerHandle PowerupTimerHandle;

	// Function bound to the overlap event
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Virtual functions to be overridden by child classes
	virtual void ApplyPowerupEffect();
	virtual void RemovePowerupEffect();

	// Hides the powerup in the world while the effect is active
	void HideAndDisable();
};