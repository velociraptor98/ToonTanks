// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"
APawnTurret::APawnTurret()
{
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Player && ReturnDistanceToPlayer() >= FireRange) {
		Super::RotateTurretFunction(Player->GetActorLocation());
	}
	
}
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	//Setting the timer for firing after set intervals of FireRate
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	Player = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}
void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
void APawnTurret::CheckFireCondition() {
	if (!Player) {
		return;
	}
	if (ReturnDistanceToPlayer() <= FireRange) {
	}
}

float APawnTurret::ReturnDistanceToPlayer() {
	if (!Player){
		return 0.0f;
	}
	return FVector::Dist(Player->GetActorLocation(), GetActorLocation());
}