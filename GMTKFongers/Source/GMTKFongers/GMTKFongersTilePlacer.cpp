// Fill out your copyright notice in the Description page of Project Settings.


#include "GMTKFongersTilePlacer.h"
#include "Engine/StaticMesh.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Kismet/KismetArrayLibrary.h"

// Sets default values
AGMTKFongersTilePlacer::AGMTKFongersTilePlacer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");

}

void AGMTKFongersTilePlacer::GenerateTiles()
{
	for (UInstancedStaticMeshComponent* InstancedStaticMesh : InstancedStaticMeshes)
	{
		InstancedStaticMesh->DestroyComponent();
	}
	
	InstancedStaticMeshes.Empty();

	for (UStaticMesh* StaticMesh : TileArray)
	{
		UInstancedStaticMeshComponent* NewInstancedStaticMesh = NewObject<UInstancedStaticMeshComponent>(this);
		NewInstancedStaticMesh->SetupAttachment(GetRootComponent());
		NewInstancedStaticMesh->RegisterComponent();
		NewInstancedStaticMesh->SetStaticMesh(StaticMesh);
		InstancedStaticMeshes.Add(NewInstancedStaticMesh);
	}

	for (int X = 0; X < FloorSize.X; X++)
	{
		for (int Y = 0; Y < FloorSize.Y; Y++)
		{
			UInstancedStaticMeshComponent* FoundInstancedStaticMesh = nullptr;
			int32 OutIndex = RandomStream.FRandRange(0, InstancedStaticMeshes.Num());
			if (InstancedStaticMeshes.IsValidIndex(OutIndex))
			{
				FoundInstancedStaticMesh = InstancedStaticMeshes[OutIndex];
			}

			if (FoundInstancedStaticMesh)
			{
				FVector Location = FVector(X * TileSize.X, Y * TileSize.Y, 0.f);
				FRotator Rotation = FRotator::ZeroRotator;
				FBox BoundingBox = FoundInstancedStaticMesh->GetStaticMesh()->GetBoundingBox();
				FVector BBExtents = BoundingBox.GetExtent() * 2;

				FVector Scale = TileSize / BBExtents;
				FTransform Transform = FTransform(Rotation.Quaternion(), Location, Scale);
				FoundInstancedStaticMesh->AddInstance(Transform, false);
			}
		}
	}
}
