// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "PushableActor.generated.h"

UCLASS()
class ANSWERHUBANSWERS_API APushableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APushableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	/** The mesh that represents the Pushable Box */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pushable Object", meta = (allowprivateaccess = true))
		UStaticMeshComponent* m_Mesh;

	/** An arrow that serves as reference to place the player character in a certain position */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pushable Object", meta = (allowprivateaccess = true))
		UArrowComponent* ArrowPlayerPlacer;

	/** Sphere that represents where to place the player character's left hand */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pushable Object", meta = (allowprivateaccess = true))
		USphereComponent* l_handPlacer;

	/** Sphere that represents where to place the player character's right hand */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pushable Object", meta = (allowprivateaccess = true))
		USphereComponent* r_handPlacer;

};
