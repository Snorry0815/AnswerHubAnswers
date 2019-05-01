#include "PushableActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APushableActor::APushableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create the mesh property and assign it as the root
	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Display Mesh"));
	SetRootComponent(m_Mesh);

	//Create the arrow that represents where we want the player to be placed
	ArrowPlayerPlacer = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow Pointer"));
	ArrowPlayerPlacer->SetupAttachment(RootComponent);

	l_handPlacer = CreateDefaultSubobject<USphereComponent>(TEXT("Left Hand Ref"));
	l_handPlacer->InitSphereRadius(5.0f);
	l_handPlacer->SetupAttachment(RootComponent);

	r_handPlacer = CreateDefaultSubobject<USphereComponent>(TEXT("Right Hand Ref"));
	r_handPlacer->InitSphereRadius(5.0f);
	r_handPlacer->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APushableActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APushableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}