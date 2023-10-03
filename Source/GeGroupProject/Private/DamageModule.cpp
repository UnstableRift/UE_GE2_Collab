// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageModule.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values for this component's properties
UDamageModule::UDamageModule()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Value stuff
	IsDead = false;
	respawnTime = 3.0f;
	RespawnLocation = FVector(900.0f, 1110.0f, 92.0f);
	PlayerHealth = 1.0f;
	// ...
}


// Called when the game starts
void UDamageModule::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("InCorrectPlayerSelected"));
	//Add Input Mapping Context
	//if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	//	{
	//		//Subsystem->AddMappingContext(DefaultMappingContext, 0);
	//	}
	//}
	
}

void UDamageModule::TakeDamage(float damageAmmount)
{
	if (!IsDead)
	{
		UE_LOG(LogTemp, Warning, TEXT("Took %f points of damage"), damageAmmount)
			PlayerHealth -= damageAmmount;
		if (PlayerHealth <= 0.00f)
		{
			OnDeath();
		}
	}
}
void UDamageModule::OnDeath()
{
	IsDead = true;
	// Set death animation form character blueprint. I don´t have an animaton :(
	GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &UDamageModule::Respawn, respawnTime, false);
}
void UDamageModule::Respawn()
{
	//SetActorLocation(RespawnLocation);
	PlayerHealth = 1.0f;
	IsDead = false;
}

// Called every frame
void UDamageModule::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

