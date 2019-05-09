// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QARotationUtils.generated.h"

/**
 * 
 */
UCLASS()
class ANSWERHUBANSWERS_API UQARotationUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void QuatYawRotate(APawn* pawn, float yawRotation);
};
