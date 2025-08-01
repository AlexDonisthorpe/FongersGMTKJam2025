
#include "FongersInteractionComponent.h"
#include "GameFramework/Actor.h"

UFongersInteractionComponent::UFongersInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UFongersInteractionComponent::CanInteract_Implementation() const
{
	return inhibitRequests <= 0;
}

bool UFongersInteractionComponent::RequestTapInteraction(AActor* InteractingActor)
{
	if (InteractingActor == nullptr)
	{
		return false;
	}
	
	if (CanInteract())
	{
		ServerStartTapInteraction(InteractingActor);
		return true;
	}

	return false;
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

void UFongersInteractionComponent::ServerStartTapInteraction_Implementation(AActor* InteractingActor)
{
	if (GetOwner()->HasAuthority())
	{
		return;
	}
	
	if (InteractingActor == nullptr)
	{
		return;
	}

	if (!CanInteract())
	{
		return;
	}

	PerformTapInteraction(InteractingActor);
}
