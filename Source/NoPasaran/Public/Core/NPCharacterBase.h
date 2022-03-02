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
	TArray<TSubclassOf<UNPGameplayAbility>> GameplayAbilities;

	UPROPERTY()
	bool bAbilitiesInitiallized = false;

	void AddStartupGameplayAbilities();

	// События для реализации получения урона и смерти.

	// И эта дрисня из примера работать не будет... Блеск. Ладно, потом надо разобраться.
	// Пример, как я понял, криво сдёрнут из ActionRPG. Там потом и посмотрим.
	// И мне не нравится тема с BlueprintImplementableEvent.
	// Также сюда предлагается пихнуть комментарий из указанного проекта к этим функциям.

	/**
	 * Called when character takes damage, which may have killed them
	 *
	 * @param DamageAmount Amount of damage that was done, not clamped based on current health
	 * @param HitInfo The hit info that generated this damage
	 * @param DamageTags The gameplay tags of the event that did the damage
	 * @param InstigatorCharacter The character that initiated this damage
	 * @param DamageCauser The actual actor that did the damage, might be a weapon or projectile
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(float DamageAmount, const FHitResult& HitInfo, const struct FGameplayTagContainer& DamageTags, ANPCharacterBase* InstigatorCharacter, AActor* DamageCauser);

	/**
	 * Called when health is changed, either from healing or from being damaged
	 * For damage this is called in addition to OnDamaged/OnKilled
	 *
	 * @param DeltaValue Change in health value, positive for heal, negative for cost. If 0 the delta is unknown
	 * @param EventTags The gameplay tags of the event that changed mana
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);

	// А вот за эти функции будет дёргать AttributeSet, когда будут срабатывать указанные выше события в блюпринтах.
	virtual void HandleDamage(float DamageAmount, const FHitResult& HitInfo, const struct FGameplayTagContainer& DamageTags, ANPCharacterBase* InstigatorCharacter, AActor* DamageCauser);

	virtual void HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);

	// Это чтобы, собственно, этот самый атрибут сет мог дёргать на функции.
	// Friended to allow access to handle functions above
	friend UNPAttributeSet;

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
