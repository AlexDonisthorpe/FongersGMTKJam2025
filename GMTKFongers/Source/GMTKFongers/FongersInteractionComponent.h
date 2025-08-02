// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "FongersInteractionComponent.generated.h"

class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class UFongersInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

	UFongersInteractionComponent();	
public:
	UFUNCTION(BlueprintPure)
	FName GetItemName() const { return ItemName; };
	
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool CanInteract(AActor* InteractingActor) const;

	UFUNCTION(BlueprintPure)
	AActor* GetInteractingActor() const { return CurrentInteractingActor.Get(); }

	UFUNCTION(BlueprintNativeEvent)
	void PerformTapInteraction(AActor* InteractingActor);

	// Make sure you call this when you're done
	UFUNCTION(BlueprintNativeEvent)
	void InteractionComplete();
	
private:
	int32 InhibitRequests { 0 };

	UPROPERTY(EditAnywhere)
	FName ItemName;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> CurrentInteractingActor;
};
