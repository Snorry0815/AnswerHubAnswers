#include "StickyComponent.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"

UStickyComponent::UStickyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UStickyComponent::BeginPlay()
{
	Super::BeginPlay();

	auto* OwnerAsCharacter = Cast<ACharacter>(GetOwner());

	OwnerSkeletalMesh = OwnerAsCharacter->GetMesh();
	OwnerCapsule = OwnerAsCharacter->GetCapsuleComponent();

	// Register component to receive actor hit (collision) events
	OwnerAsCharacter->OnActorHit.AddDynamic(this, &UStickyComponent::OnActorHit);
}

void UStickyComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (CanStick(OtherActor))
	{
		auto* Owner = GetOwner();

		OwnerCapsule->IgnoreActorWhenMoving(OtherActor, true);

		auto* rootAsPrimitive = Cast<UPrimitiveComponent>(OtherActor->GetRootComponent());
		if (rootAsPrimitive)
		{
			rootAsPrimitive->SetSimulatePhysics(false);
		}


		auto AttachLocation =  GetAttachLocation();
		OtherActor->SetActorLocation(AttachLocation);
		FName BoneNameToAttachTo = GetClosestBone(AttachLocation);
		FAttachmentTransformRules AttachmentRules{EAttachmentRule::KeepWorld, true};
		OtherActor->AttachToComponent(OwnerSkeletalMesh, AttachmentRules, BoneNameToAttachTo);
	}
}

// Find out if hit object can stick 
// As an example I used a tag to identify any stickable objects
bool UStickyComponent::CanStick(AActor* actor) const
{
	return actor->ActorHasTag("StickAble");
}

// Find the location to attach your object to
// As an example I get a random point on the skeletal mesh
FVector UStickyComponent::GetAttachLocation() const
{
	FCollisionQueryParams Params;
	FHitResult Hit;

	FVector EndPoint = OwnerCapsule->GetComponentLocation();
	FVector RandomStart = EndPoint + FMath::VRand() * OwnerCapsule->GetScaledCapsuleHalfHeight();

	if (OwnerSkeletalMesh->LineTraceComponent(Hit, RandomStart, EndPoint, Params))
	{
		return Hit.ImpactPoint;
	}

	return EndPoint;
}

// Since I wanted to attach to the skeletal mesh
// I also wanted that the object animates with the skeletal mesh
// to achieve this i need to attach the object to the closest bone 
// to my attach location
FName UStickyComponent::GetClosestBone(const FVector& LocationInQuestion) const
{
	TArray<FName> BoneNames;
	OwnerSkeletalMesh->GetBoneNames(BoneNames);

	FName ClosestBoneName = NAME_None;
	float ClosestSquaredDistance = -1.0f;
	for (const auto& BoneName : BoneNames)
	{
		auto BoneLocation = OwnerSkeletalMesh->GetBoneLocation(BoneName);
		float SquaredDistance = FVector::DistSquared(BoneLocation, LocationInQuestion);
		if ((ClosestSquaredDistance < 0.0f) || (SquaredDistance < ClosestSquaredDistance))
		{
			ClosestSquaredDistance = SquaredDistance;
			ClosestBoneName = BoneName;
		}
	}

	return ClosestBoneName;
}
