// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GMTKFongersTilePlacer.generated.h"

class UStaticMesh;
class UInstancedStaticMeshComponent;

UCLASS(Blueprintable, Placeable)
class GMTKFONGERS_API AGMTKFongersTilePlacer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGMTKFongersTilePlacer();

	UFUNCTION(CallInEditor)
	void GenerateTiles();

private:
	UPROPERTY(EditAnywhere)
	FVector2D FloorSize;

	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> TileArray;

	UPROPERTY(EditAnywhere)
	FVector TileSize;

	UPROPERTY(EditAnywhere)
	FRandomStream RandomStream;

	TArray<UInstancedStaticMeshComponent*> InstancedStaticMeshes;

	UPROPERTY(Transient)
	USceneComponent* RootSceneComponent = nullptr;
};
