

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

// Reverse direction of motion if gone too far
void AMovingPlatform::MovePlatform(float DeltaTime) 
{		
	if (ShouldPlatformReturn()) 
	{
		ReversePlatformDirection();
	}
	else 
	{
		MovePlatformForward();
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);
}


float AMovingPlatform::GetDistanceMoved() const
{
	return (FVector::Dist(StartLocation, GetActorLocation()));
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return (GetDistanceMoved() > MoveDistance);
}


void AMovingPlatform::ReversePlatformDirection() 
{
	FVector MovementDirection = PlatformVelocity.GetSafeNormal();
	StartLocation = StartLocation + MovementDirection * MoveDistance;
	SetActorLocation(StartLocation);

	PlatformVelocity = -PlatformVelocity;
}


void AMovingPlatform::MovePlatformForward() 
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);
}