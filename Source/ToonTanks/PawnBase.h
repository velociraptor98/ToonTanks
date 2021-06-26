// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;
class USceneComponent;
UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()
 
public:
	APawnBase();
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "Components")
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
		UCapsuleComponent* Capsule;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
		USceneComponent* ProjectileSpawnPoint;

protected: 
	void RotateTurretFunction(FVector LookAtTarget);
	void Fire();
	virtual void HandleDestruction();


};
