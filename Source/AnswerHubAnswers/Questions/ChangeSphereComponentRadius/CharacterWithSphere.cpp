#include "CharacterWithSphere.h"
#include "Components/SphereComponent.h"

ACharacterWithSphere::ACharacterWithSphere()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("USphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->InitSphereRadius(500.0f);
}

void ACharacterWithSphere::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACharacterWithSphere::OnInteractorBeginOverlap);
}

void ACharacterWithSphere::OnInteractorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("So Overlappy!"));
}