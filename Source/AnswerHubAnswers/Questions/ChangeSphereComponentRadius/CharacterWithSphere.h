// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "AnswerHubAnswers/AnswerHubAnswersCharacter.h"

#include "CharacterWithSphere.generated.h"

class USphereComponent;

UCLASS(config = Game)
class ACharacterWithSphere : public AAnswerHubAnswersCharacter
{
	GENERATED_BODY()

public:
	ACharacterWithSphere();

	void BeginPlay() override;

protected:
	UFUNCTION()
	void OnInteractorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;
};
