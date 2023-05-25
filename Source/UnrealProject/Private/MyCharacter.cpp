// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("MyCharacter beginPlay."));
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);

	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);

	PlayerInputComponent->BindAction("StartJump", IE_Pressed, this, &AMyCharacter::StartJump);

	PlayerInputComponent->BindAction("StopJump", IE_Released, this, &AMyCharacter::StopJump);

}

void AMyCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMyCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AMyCharacter::StartJump()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

