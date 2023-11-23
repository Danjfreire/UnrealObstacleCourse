// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetActorLocation();
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AMovingActor::Move(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	SetActorLocation(CurrentLocation + MovementSpeed * DeltaTime);

	if (GetMoveDistance() > MaxMoveDistance)
	{
		// Reset starting location
		StartingLocation = StartingLocation + MovementSpeed.GetSafeNormal() * MaxMoveDistance;

		// Revert movement
		MovementSpeed *= -1;
	}
}

float AMovingActor::GetMoveDistance() const
{
	return FVector::Dist(StartingLocation, GetActorLocation());
}
