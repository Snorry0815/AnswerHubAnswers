// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "CanNotEditComponents.generated.h"

UCLASS()
class ANSWERHUBANSWERS_API ACanNotEditComponents : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACanNotEditComponents();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pushable Object", meta = (allowprivateaccess = true))
	USceneComponent* DummyRoot;

	/** The mesh that represents the Pushable Box */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pushable Object", meta = (allowprivateaccess = true))
	TArray<UStaticMeshComponent*> Pipelines;


};
