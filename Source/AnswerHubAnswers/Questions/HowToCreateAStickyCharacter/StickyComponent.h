// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StickyComponent.generated.h"


class USkeletalMeshComponent;
class UCapsuleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANSWERHUBANSWERS_API UStickyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStickyComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	bool CanStick(AActor* actor) const;
	FVector GetAttachLocation() const;
	FName GetClosestBone(const FVector& LocationInQuestion) const;

	UPROPERTY()
	USkeletalMeshComponent* OwnerSkeletalMesh;

	UPROPERTY()
	UCapsuleComponent* OwnerCapsule;
};
