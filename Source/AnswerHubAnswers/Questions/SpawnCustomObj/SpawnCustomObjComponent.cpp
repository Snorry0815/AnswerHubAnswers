// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnCustomObjComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
USpawnCustomObjComponent::USpawnCustomObjComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnCustomObjComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnCustomObjComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void USpawnCustomObjComponent::Spawn()
{
	FVector Location = GetOwner()->GetActorLocation() + FVector{ 0.0f, 0.0f, 100.0f };
	FActorSpawnParameters Params{};
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(BalloonClassToSpawn, Location, FRotator::ZeroRotator, Params);
}