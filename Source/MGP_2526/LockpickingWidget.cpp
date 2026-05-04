// Fill out your copyright notice in the Description page of Project Settings.


#include "LockpickingWidget.h"
#include "Components/Image.h"
#include "Math/UnrealMathUtility.h"
#include "Input/Events.h"

void ULockpickingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//This generates the sweet spot anywhere between -90 and 90 degrees
	SweetSpotAngle = FMath::RandRange(-90.0f, 90.0f);

	PickAngle = 0.0f;
	CurrentLockAngle = 0.0f;
	bIsTurningLock = false;


}

FReply ULockpickingWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseMove(InGeometry, InMouseEvent);

	//only moves the pick if player isnt turning the lock
	if (!bIsTurningLock)
		float MouseDeltaX = InMouseEvent.GetCursorDelta().X;
		// adjusts the sensitivity
		//PickAngle += MouseDeltaX * 0.0f;
	float MouseDeltaX = static_cast<float>(InMouseEvent.GetCursorDelta().X);
		PickAngle = FMath::Clamp(PickAngle, -90.0f, 90.0f);

		if (PickImage)
			PickImage->SetRenderTransformAngle(PickAngle);

		return FReply::Handled();
}

void ULockpickingWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	//determines how far the lock is allowed to turn
	float DistanceToSweetSpot = FMath::Abs(PickAngle - SweetSpotAngle);

	if (DistanceToSweetSpot <= Tolerance)
		MaxLockTurn = 90.0f; //Perfect hit
	else
		// maps the distance to a lock angle, Wont turn if too far away
		MaxLockTurn = FMath::GetMappedRangeValueClamped(
			FVector2D(Tolerance, 90.0f),
			FVector2D(90.0f, 0.0f),
			DistanceToSweetSpot
		);
	
	// code to handle the lock rotation
	if (bIsTurningLock)
		CurrentLockAngle = FMath::FInterpTo(CurrentLockAngle, MaxLockTurn, InDeltaTime, 5.0f);
	else
		// value goes to 0 when player stops moving the lock
		CurrentLockAngle = FMath::FInterpTo(CurrentLockAngle, 0.0f, InDeltaTime, 10.0f);

	if (LockImage)
		LockImage->SetRenderTransformAngle(CurrentLockAngle);

	//win condition
	if (CurrentLockAngle >= 89.0f)
		RemoveFromParent();
}

void ULockpickingWidget::StartTurningLock()
{
	bIsTurningLock = true;
}

void ULockpickingWidget::StopTurningLock()
{
	bIsTurningLock = false;
}