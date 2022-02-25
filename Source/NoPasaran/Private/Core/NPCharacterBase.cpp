// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/NPCharacterBase.h"

#include "GAS/NPGameplayAbility.h"
#include "GAS/NPAbilitySystemComponent.h"
#include "GAS/NPAttributeSet.h"

#include "GameplayEffect.h"

// Sets default values
ANPCharacterBase::ANPCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UNPAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	//Разобраться, как лучше
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UNPAttributeSet>(TEXT("AttributeSet"));

}

UAbilitySystemComponent* ANPCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ANPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server GAS init
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void ANPCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Client side GAS init
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	// Bind input to Ability System
	if (AbilitySystemComponent && InputComponent)
	{
		// Привязки GAS
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"ENPAbilityInputID",
			static_cast<int32>(ENPAbilityInputID::Confirm),
			static_cast<int32>(ENPAbilityInputID::Cancel));

		// И связываем инпуты с GAS
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);

		// Для верности советуют задублировать это мероприятие в SetupPlayerInputComponent
	}
}

void ANPCharacterBase::EquipWeapon(AActor* Weapon)
{
	if (Weapon && EquippedWeapon != Weapon)
	{
		// Здесь, думается, нужно будет репликацию прикручивать.
		EquippedWeapon = Weapon;
		// Вот прямо тут. Хотя, тут же будет абилитя.
		//ASC->CallAbility(EquipMeleeWeapon)
	}
}

void ANPCharacterBase::DoMeleeAttack()
{
	if (!MeleeWeapon)
	{
		return;
	}

	if (EquippedWeapon != MeleeWeapon)
	{
		//ASC->CallAbility(EquipWeapon(MeleeWeapon))
	}

	//ASC->CallAbility(MeleeAttack)
}

void ANPCharacterBase::DoRangedAttack()
{
	if (!MeleeWeapon)
	{
		return;
	}

	if (EquippedWeapon != MeleeWeapon)
	{

	}
}

// Called every frame
void ANPCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind input to Ability System
	if (AbilitySystemComponent && InputComponent)
	{
		// Привязки GAS
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"ENPAbilityInputID",
			static_cast<int32>(ENPAbilityInputID::Confirm),
			static_cast<int32>(ENPAbilityInputID::Cancel));

		// И связываем инпуты с GAS
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

