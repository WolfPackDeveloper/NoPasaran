// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCharacterPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ANPCharacterPlayer::ANPCharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetMesh()->SetGenerateOverlapEvents(true);
}

void ANPCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ANPCharacterPlayer::MoveForward(float AxisValue)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;
	
	AddMovementInput(ControlRotation.Vector(), AxisValue);
}

void ANPCharacterPlayer::MoveRight(float AxisValue)
{
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, AxisValue);
}

void ANPCharacterPlayer::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANPCharacterPlayer::TurnRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANPCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANPCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForvard", this, &ANPCharacterPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANPCharacterPlayer::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRight", this, &ACharacter::AddControllerYawInput);
	//Gamepad turning
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANPCharacterPlayer::LookUpRate);
	PlayerInputComponent->BindAxis("TurnRightRate", this, &ANPCharacterPlayer::TurnRightRate);
}
