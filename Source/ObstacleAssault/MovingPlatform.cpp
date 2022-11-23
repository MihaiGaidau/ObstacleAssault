// Fill out your copyright notice in the Description page of Project Settings.

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

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("Begin Play: %s"), *Name);
	UE_LOG(LogTemp, Warning, TEXT("Hello from Heaven"));
	UE_LOG(LogTemp, Error, TEXT("Hello from Heaven"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatfor(DeltaTime);
	RotatePlatform(DeltaTime);

}


void AMovingPlatform::MovePlatfor(float DeltaTime){
		// Move platfor forwards
	// Get current location
	FVector CurrentLocation = GetActorLocation();
	// Add vector to that location
	CurrentLocation += PlatformVelocity * DeltaTime;
	// Set the location
	SetActorLocation(CurrentLocation);
	// Set Platfor back if gone to far
	// Check how far we'he moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	// Reverse direction of motion if gone to far
	if (DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("Platform %s OverShoot: %.2f"),*GetName(), OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime){
	UE_LOG(LogTemp, Display, TEXT("Rotating... %s"),*GetName());
}
