// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageModule.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GEGROUPPROJECT_API UDamageModule : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health")
	float PlayerHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool IsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float respawnTime;

	FTimerHandle RespawnTimer;
	FVector RespawnLocation;


public:	
	// Sets default values for this component's properties
	UDamageModule();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Mario like code additions
	void OnDeath();

	UFUNCTION(BlueprintCallable)
	void Respawn();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float damageAmmount);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
