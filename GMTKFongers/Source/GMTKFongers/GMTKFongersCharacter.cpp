// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMTKFongersCharacter.h"
#include "FongersInteractionFacilitator.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "ItemClassData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AGMTKFongersCharacter

AGMTKFongersCharacter::AGMTKFongersCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);


	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	FirstPersonItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("First Person Item Mesh"));
	FirstPersonItemMesh->SetupAttachment(FirstPersonMesh, FName("Item_Attach_Socket"));
	FirstPersonItemMesh->SetOnlyOwnerSee(true);
	FirstPersonItemMesh->SetCollisionProfileName(FName("NoCollision"));
	FirstPersonItemMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonItemMesh->SetVisibility(false);

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;
	
	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	ThirdPersonItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Third Person Item Mesh"));
	ThirdPersonItemMesh->SetupAttachment(GetMesh(), FName("Item_Attach_Socket"));
	ThirdPersonItemMesh->SetCollisionProfileName(FName("NoCollision"));
	ThirdPersonItemMesh->SetOwnerNoSee(true);
	ThirdPersonItemMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;
	ThirdPersonItemMesh->SetVisibility(false);

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	InteractionFacilitator = CreateDefaultSubobject<UFongersInteractionFacilitator>(TEXT("Interaction Component"));
}

void AGMTKFongersCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AGMTKFongersCharacter::DoJumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AGMTKFongersCharacter::DoJumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGMTKFongersCharacter::MoveInput);

		// Looking/Aiming
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGMTKFongersCharacter::LookInput);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AGMTKFongersCharacter::LookInput);

		// Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this , &AGMTKFongersCharacter::InteractPressed);
		EnhancedInputComponent->BindAction(DropAction, ETriggerEvent::Triggered, this, &AGMTKFongersCharacter::DropRequested);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AGMTKFongersCharacter::Server_DropItem_Implementation()
{
	if (ItemHolding.Get() == nullptr)
	{
		return;
	}

	FVector DropLocation = GetActorLocation() + GetActorForwardVector() * DropOffset.Z;

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(
		ItemHolding->WorldActorClass.Get(),
		DropLocation,
		GetActorRotation());

	if (NewActor)
	{
		ItemHolding = nullptr;
	}
}

void AGMTKFongersCharacter::MoveInput(const FInputActionValue& Value)
{
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);

}

void AGMTKFongersCharacter::LookInput(const FInputActionValue& Value)
{
	// get the Vector2D look axis
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// pass the axis values to the aim input
	DoAim(LookAxisVector.X, LookAxisVector.Y);

}

void AGMTKFongersCharacter::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		// pass the rotation inputs
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AGMTKFongersCharacter::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		// pass the move inputs
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void AGMTKFongersCharacter::DoJumpStart()
{
	// pass Jump to the character
	Jump();
}

void AGMTKFongersCharacter::DoJumpEnd()
{
	// pass StopJumping to the character
	StopJumping();
}

void AGMTKFongersCharacter::DropRequested()
{
	if (GetIsHoldingItem())
	{
		Server_DropItem();
	}
}

void AGMTKFongersCharacter::Authority_HoldItem(UItemClassData* ItemToHold)
{
	if (!HasAuthority())
	{
		return;
	}
	
	ItemHolding = ItemToHold;
}

void AGMTKFongersCharacter::OnRep_ItemHolding()
{
	UStaticMeshComponent*& TempPointerToMesh = IsLocallyControlled() ? FirstPersonItemMesh : ThirdPersonItemMesh;
	
	if (ItemHolding)
	{
		FirstPersonItemMesh->SetWorldScale3D(ItemHolding->Scale);
		FirstPersonItemMesh->SetStaticMesh(ItemHolding->StaticMesh);
		FirstPersonItemMesh->SetVisibility(true);

		ThirdPersonItemMesh->SetWorldScale3D(ItemHolding->Scale);
		ThirdPersonItemMesh->SetStaticMesh(ItemHolding->StaticMesh);
		ThirdPersonItemMesh->SetVisibility(true);
	}
	else
	{
		FirstPersonItemMesh->SetVisibility(false);
		ThirdPersonItemMesh->SetVisibility(false);
	}
}

void AGMTKFongersCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGMTKFongersCharacter, ItemHolding)
}

void AGMTKFongersCharacter::InteractPressed(const FInputActionValue& InputActionValue)
{
	if (InteractionFacilitator)
	{
		InteractionFacilitator->InteractionRequested();
	}
}
