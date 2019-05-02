
#include "CanNotEditComponents.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACanNotEditComponents::ACanNotEditComponents()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create the mesh property and assign it as the root
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRoot"));
	SetRootComponent(DummyRoot);



	for (int32 i = 0; i < 4; ++i)
	{
		Pipelines.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString("Pipelines" + FString::FromInt(i))));
		Pipelines[i]->SetupAttachment(DummyRoot);
	}
}
