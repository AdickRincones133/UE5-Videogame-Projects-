
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Used to set Velocity, Distance and velocity of the platform
	UPROPERTY(EditAnywhere, Category="Move")
	FVector PlatformVelocity;
	
	UPROPERTY(EditAnywhere, Category="Move")
	float MoveDistance;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

private:

	FVector StartLocation;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	float GetDistanceMoved() const;

	bool ShouldPlatformReturn() const;

	void ReversePlatformDirection();

	void MovePlatformForward();
};
