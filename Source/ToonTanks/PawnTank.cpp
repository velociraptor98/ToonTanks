// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

void APawnTank::CalculateMoveInput(float value)
{
	MoveDirection = FVector(value * MoveSpeed * GetWorld()->DeltaTimeSeconds,0,0);
}

void APawnTank::CalculateRotateInput(float value)
{
	float RotateAmount = value * RotSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0, RotateAmount,0);
	RotationDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
	AddActorLocalRotation(RotationDirection,true);
}

//Constructor
APawnTank::APawnTank() {
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);
}

// Called Every Frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();
	Move();
}
// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();
}
