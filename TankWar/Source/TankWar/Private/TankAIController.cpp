// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller can't find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller finds %s"), *(ControlledTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		// Move towards player
		//Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if req
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) 
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}