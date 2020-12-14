// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kart.generated.h"

UCLASS()
class RACINGGAME_API AKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Mass of car in Kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	//Force pplied to the car when throttle is fully down N
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	//Number of dregres rotated per second at full control throw
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;

	void MoveForward(float value);
	void MoveRight(float value);
	void UpdateLocationFromVelocity(float DeltaTime);
	void ApplyRotation(float DeltaTime);

	FVector Velocity;

	float Throttle;
	float SteeringThrow;

};
