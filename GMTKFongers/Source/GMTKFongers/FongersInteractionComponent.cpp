
#include "FongersInteractionComponent.h"
#include "GameFramework/Actor.h"

UFongersInteractionComponent::UFongersInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
}

bool UFongersInteractionComponent::CanInteract_Implementation(AActor* InteractingActor) const
{
	return true;
}

void UFongersInteractionComponent::InteractionComplete_Implementation()
{
	CurrentInteractingActor = nullptr;
}

void UFongersInteractionComponent::PerformTapInteraction_Implementation(AActor* InteractingActor)
{
	if (InteractingActor == nullptr)
	{
		return;
	}

	CurrentInteractingActor = InteractingActor;
}
