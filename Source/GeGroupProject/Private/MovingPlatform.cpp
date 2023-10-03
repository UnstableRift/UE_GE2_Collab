#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    InitialLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!IsMoving && !IsRotating) return;

    if (IsMoving) {
        FVector NewLocation = InitialLocation + DirectionVector * (FMath::Sin(Frequency * GetGameTimeSinceCreation()) * Amplitude);

        SetActorLocation(NewLocation);
    }

    if (IsRotating) {
        FRotator NewRotation = GetActorRotation();
        NewRotation.Yaw += RotationSpeed * DeltaTime;

        SetActorRotation(NewRotation);
    }
}
