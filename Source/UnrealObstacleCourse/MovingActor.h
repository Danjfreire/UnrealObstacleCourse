// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class UNREALOBSTACLECOURSE_API AMovingActor : public AActor
{
	GENERATED_BODY()

	FVector StartingLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MovementSpeed = FVector(300, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxMoveDistance = 1000;

public:
	// Sets default values for this actor's properties
	AMovingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);
	inline float GetMoveDistance() const;
};
