#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"
#include "MovingPlatform.generated.h"

//LEARNINGUNREAL_API
UCLASS()
class AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // Movement
    UPROPERTY(EditAnywhere, Category = "PlatformMovementSettings")
    bool IsMoving;

    UPROPERTY(EditAnywhere, Category = "PlatformMovementSettings")
    FVector DirectionVector;

    UPROPERTY(EditAnywhere, Category = "PlatformMovementSettings")
    float Amplitude;

    UPROPERTY(EditAnywhere, Category = "PlatformMovementSettings")
    float Frequency;

    // Rotation
    UPROPERTY(EditAnywhere, Category = "PlatformRotationSettings")
    bool IsRotating;

    UPROPERTY(EditAnywhere, Category = "PlatformRotationSettings")
    float RotationSpeed;

    FVector InitialLocation;
};