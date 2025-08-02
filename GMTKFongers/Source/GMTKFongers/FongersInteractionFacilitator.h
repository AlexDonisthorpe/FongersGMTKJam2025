// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingSystem/TargetingSubsystem.h"
#include "TargetingSystem/TargetingPreset.h"
#include "FongersInteractionFacilitator.generated.h"

class UFongersInteractionComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UFongersInteractionFacilitator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFongersInteractionFacilitator();

	void InteractionRequested();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void TargetingResult(FTargetingRequestHandle TargetingRequestHandle);
	virtual void ScanForInteractables();

	UFUNCTION(Server, Reliable)
	virtual void ServerStartTapInteraction(UFongersInteractionComponent* InteractionComponent);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UTargetingPreset> TargetingPreset;

	UPROPERTY(BlueprintReadOnly, Category="Interaction")
	TObjectPtr<UTargetingSubsystem> TargetingSubsystem;

	UPROPERTY(Transient)
	TArray<AActor*> CurrentInteractableActors;

	FTargetingRequestDelegate CompletionDelegate;
};
