// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "NoPasaran.h"
#include "GAS/NPAbilitySystemComponent.h"
#include "GAS/NPAttributeSet.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "NPCharacterBase.generated.h"

class UNPAbilitySystemComponent;
class UNPAttributeSet;

class UGameplayEffect;

UCLASS()
class NOPASARAN_API ANPCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	
	/** The component used to handle ability system interactions */
	UPROPERTY()
	UNPAbilitySystemComponent* AbilitySystemComponent;

	/** List of attributes modified by the ability system */
	UPROPERTY()
	UNPAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* MeleeWeapon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* RangeWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* EquippedWeapon;

	//Блеать, херня какая-то... Всё не так.
	/** Passive gameplay effects that initializes attributes defaults */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ""Abilities"")
	//TArray<TSubclassOf<UGameplayEffect>> DefaultAttributesEffects;


	/** Abilities to grant to this character on creation. These will be activated by tag or event and are not bound to specific inputs */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	//TArray<TSubclassOf<URPGGameplayAbility>> GameplayAbilities;

	/** Passive gameplay effects applied on creation */
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Abilities)
	//TArray<TSubclassOf<UGameplayEffect>> PassiveGameplayEffects;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UFUNCTION()
	void EquipWeapon(AActor* Weapon);

	UFUNCTION()
	void DoMeleeAttack();

	UFUNCTION()
	void DoRangedAttack();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
