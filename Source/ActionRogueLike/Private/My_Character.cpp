// Fill out your copyright notice in the Description page of Project Settings.


#include "My_Character.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMy_Character::AMy_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp1");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp1");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AMy_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMy_Character::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMy_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}


// Called every frame
void AMy_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMy_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMy_Character::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMy_Character::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

