// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSettings.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameModeBase.h"

void UDamageSettings::OnBulletHit(AActor* SelfActor) {
	if (auto* Target = Cast<AActor>(SelfActor))
	{
		if (auto* GM = Cast<AGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			UE_LOG(LogTemp, Error, TEXT("SayWhat"));
		}
	}

}