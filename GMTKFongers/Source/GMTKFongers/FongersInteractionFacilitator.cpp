// Fill out your copyright notice in the Description page of Project Settings.


#include "FongersInteractionFacilitator.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

#include "FongersInteractionComponent.h"
#include "GMTKFongersCharacter.h"

// Sets default values for this component's properties
UFongersInteractionFacilitator::UFongersInteractionFacilitator()
{
	PrimaryComponentTick.TickInterval = 0.3f;
	PrimaryComponentTick.bCanEverTick = true;
}

void UFongersInteractionFacilitator::InteractionRequested()
{
	if (CurrentInteractableActors.IsEmpty())
	{
		if (AGMTKFongersCharacter* Character = Cast<AGMTKFongersCharacter>(GetOwner()))
		{
			if (Character->GetIsHoldingItem())
			{
				Character->Server_DropItem();
			}
		}
		return;
	}

	UFongersInteractionComponent* InteractionComponent = nullptr;
	for (const AActor* Actor : CurrentInteractableActors)
	{
		InteractionComponent = Actor->GetComponentByClass<UFongersInteractionComponent>();
		if (InteractionComponent != nullptr && InteractionComponent->CanInteract(GetOwner()))
		{
			break;
		}
	}

	if (!InteractionComponent)
	{
		return;
	}

	ServerStartTapInteraction(InteractionComponent);
}


void UFongersInteractionFacilitator::BeginPlay()
{
	Super::BeginPlay();

	CompletionDelegate.BindUObject(this, &ThisClass::TargetingResult);
	TargetingSubsystem = UTargetingSubsystem::GetTargetingSubsystem(GetWorld());
}

void UFongersInteractionFacilitator::TargetingResult(FTargetingRequestHandle TargetingRequestHandle)
{
	CurrentInteractableActors.Empty();
	TargetingSubsystem->GetTargetingResultsActors(TargetingRequestHandle, CurrentInteractableActors);
}

void UFongersInteractionFacilitator::ScanForInteractables()
{
	if (!TargetingPreset)
	{
		return;
	}

	if (TargetingSubsystem)
	{
		FTargetingSourceContext Context;
		Context.SourceActor = GetOwner();
		
		UTargetingPreset* Preset = TargetingPreset;
	
		auto TargetingHandle = UTargetingSubsystem::MakeTargetRequestHandle(Preset, Context);
	
		TargetingSubsystem->StartAsyncTargetingRequestWithHandle(TargetingHandle, CompletionDelegate);
	}
}

void UFongersInteractionFacilitator::ServerStartTapInteraction_Implementation(UFongersInteractionComponent* InteractionComponent)
{
	if (!InteractionComponent)
	{
		return;
	}
	
	if (InteractionComponent->CanInteract(GetOwner()))
	{
		InteractionComponent->PerformTapInteraction(GetOwner());
	}
}

void UFongersInteractionFacilitator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ScanForInteractables();
}
