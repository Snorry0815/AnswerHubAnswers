// Fill out your copyright notice in the Description page of Project Settings.


#include "QARotationUtils.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"

void UQARotationUtils::QuatYawRotate(APawn* Pawn, float YawRotation)
{
	auto* Controller = Pawn->GetController();
	if (!Controller)
		return;

	auto CurrentRotation = Controller->GetControlRotation();
	FQuat NewQuatRotation = CurrentRotation.Quaternion() * FQuat { 0, 0, 1, YawRotation};
	Controller->SetControlRotation(NewQuatRotation.Rotator());
}
