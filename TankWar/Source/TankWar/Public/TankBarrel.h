// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hideCategories = ("Collision"))
class TANKWAR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public :
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
	
};
