#pragma once

#include "GameFramework/PlayerController.h"
#include "StartSpectatingPlayerController.generated.h"

UCLASS()
class AStartSpectatingPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnRep_Pawn() override;

	UFUNCTION(BlueprintCallable, Category = "Start Spectating Player Controller")
	void StartSpectating();

	UFUNCTION(Client, Reliable)
	void Client_StartSpectating();

	UFUNCTION(BlueprintCallable, Category = "Start Spectating Player Controller")
	void StartPlaying();
};