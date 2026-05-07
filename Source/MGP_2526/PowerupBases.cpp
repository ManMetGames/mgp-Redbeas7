// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerupBases.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

APowerupBases::APowerupBases()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = CollisionSphere;
	CollisionSphere->SetSphereRadius(50.f);

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APowerupBases::OnOverlapBegin);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PowerupDuration = 5.0f; // Default duration is 5 seconds
}


void APowerupBases::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TargetCharacter = Cast<ACharacter>(OtherActor);

	if (TargetCharacter)
	{
		ApplyPowerupEffect();
		HideAndDisable();

		// Start the timer to remove the effect
		GetWorld()->GetTimerManager().SetTimer(PowerupTimerHandle, this, &APowerupBases::RemovePowerupEffect, PowerupDuration, false);
	}
}

void APowerupBases::ApplyPowerupEffect()
{
	// To be implemented in child classes
}

void APowerupBases::RemovePowerupEffect()
{
	// Once the effect is removed, destroy
	Destroy();
}

void APowerupBases::HideAndDisable()
{
	// Hides the mesh
	MeshComp->SetVisibility(false);

	// Disable collision so it can't be picked up again while active
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}