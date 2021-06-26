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
	
}
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	//Setting the timer for firing after set intervals of FireRate
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	Player = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}
void APawnTurret::CheckFireCondition() {
	if (!Player) {
		return;
	}
	if (ReturnDistanceToPlayer() <= FireRange) {
		UE_LOG(LogTemp, Warning, TEXT("TImer works"));
	}
}

float APawnTurret::ReturnDistanceToPlayer() {
	if (!Player){
		return 0.0f;
	}
	return FVector::Dist(Player->GetActorLocation(), GetActorLocation());
}