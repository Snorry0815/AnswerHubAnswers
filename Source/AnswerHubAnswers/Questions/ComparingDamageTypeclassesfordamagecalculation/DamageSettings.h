// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DamageSettings.generated.h"

/**
 * 
 */
UCLASS()
class ANSWERHUBANSWERS_API UDamageSettings : public UDataTable
{
	GENERATED_BODY()

	void OnBulletHit(AActor* SelfActor);
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Table|stuff")
	FName mapName;
};
