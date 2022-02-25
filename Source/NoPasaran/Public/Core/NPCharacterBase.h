// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/NPTypes.h"

//#include "GAS/NPGameplayAbility.h"
//#include "GAS/NPAbilitySystemComponent.h"
//#include "GAS/NPAttributeSet.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "NPCharacterBase.generated.h"

// Можно зафорвардить свои классы системы GAS. Пока не понял, как лучше.
class UNPGameplayAbility;
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
	
	// ==============================
	//		Ability System
	// ==============================

	/** The component used to handle ability system interactions */
	// Некий чувак предлагает юзать тут TObjectPTR...
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNPAbilitySystemComponent* AbilitySystemComponent;

	/** List of attributes modified by the ability system */
	UPROPERTY()
	UNPAttributeSet* AttributeSet;

	/* Effects to initialize Attributes */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> PassiveGameplayEffects;

	/* GameplayAbilities are owned by Character*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> GameplayAbilities;

	UPROPERTY()
	bool bAbilitiesInitiallized = false;

	// ==============================

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* MeleeWeapon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* RangeWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	AActor* EquippedWeapon;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

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
