// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LockpickingWidget.generated.h"

class UImage;

/**
 * 
 */
UCLASS()
class MGP_2526_API ULockpickingWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// this overrides the mouse controls while the lockpicking minigame is active
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	//code to connect a the image used for the lock "LockImage"
	UPROPERTY(meta = (BindWidget))
	UImage* LockImage;

	//code to connect the image used for the lockpick "PickImage"
	UPROPERTY(meta = (BindWidget))
	UImage* PickImage;

	// configs for the mechanic, allows more variety of difficulty
	UPROPERTY(EditAnywhere, Category = "Lockpicking")
	float Tolerance = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Lockpicking")
	float TurnSpeed = 100.0f;

	//list of variables
	float SweetSpotAngle;
	float PickAngle;
	float CurrentLockAngle;
	float MaxLockTurn;
	bool bIsTurningLock;

public:
	UFUNCTION(BlueprintCallable, Category = "Lockpicking")
	void StartTurningLock();

	UFUNCTION(BlueprintCallable, Category = "Lockpicking")
	void StopTurningLock();
};
