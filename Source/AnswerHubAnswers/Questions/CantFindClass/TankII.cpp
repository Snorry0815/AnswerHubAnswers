// Fill out your copyright notice in the Description page of Project Settings.


#include "TankII.h"

// Sets default values
ATankII::ATankII()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankII::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankII::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankII::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

