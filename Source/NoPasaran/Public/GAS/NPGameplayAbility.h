// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/NPTypes.h"
#include "Abilities/GameplayAbility.h"
#include "NPGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class NOPASARAN_API UNPGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UNPGameplayAbility();


public:
	
	/* Abilities with this set will automatically activate when the input is pressed */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	ENPAbilityInputID AbilityInputID = ENPAbilityInputID::None;
};
