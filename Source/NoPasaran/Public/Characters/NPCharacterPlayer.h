// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/NPCharacterBase.h"
#include "NPCharacterPlayer.generated.h"


class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class NOPASARAN_API ANPCharacterPlayer : public ANPCharacterBase
{
	GENERATED_BODY()
	
public:

	ANPCharacterPlayer();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	// Для ровного поворота с джойстика. Пока оставим так.
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float BaseTurnRate = 70.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void TurnRightRate(float AxisValue);

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
