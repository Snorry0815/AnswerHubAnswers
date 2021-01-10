#pragma once

#include "CoreMinimal.h"

#include "Tickable.h"
#include "Engine/Engine.h"
#include "GameFramework/CheatManager.h"

#include "TickingCheatManager.generated.h"

UCLASS(Blueprintable, BlueprintType)

class UTickingCheatManager : public UCheatManager, public FTickableGameObject
{
  GENERATED_BODY()

public:
  //~ Begin FTickableGameObject interface
  virtual TStatId GetStatId() const override
  {
    RETURN_QUICK_DECLARE_CYCLE_STAT(UTickingCheatManager, STATGROUP_Tickables);
  }
  virtual bool IsTickable() const override
  {
    return true;
  }

  virtual void Tick(float DeltaTime) override;
  //~ End FTickableGameObject interface
};

inline void UTickingCheatManager::Tick(float DeltaTime)
{
  GEngine->AddOnScreenDebugMessage(0, 0, FColor::Green, FString::SanitizeFloat(DeltaTime));
}
