// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/NPAttributeSet.h"
#include "Core/NPCharacterBase.h"
//#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UNPAttributeSet::UNPAttributeSet()
{
	// Для начала. Потом всё это должно переехать в таблицы.
	MaxHealth = 100.f;
	Health = MaxHealth;
	MaxConcentration = 100.f;
	Concentration = MaxConcentration;
	AttackPower = 10.f;
	DefensePower = 10.f;
	Damage = 0.f;

	MoveSpeed = 600.f;
}

void UNPAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UNPAttributeSet, Health);
	DOREPLIFETIME(UNPAttributeSet, MaxHealth);
	DOREPLIFETIME(UNPAttributeSet, Concentration);
	DOREPLIFETIME(UNPAttributeSet, MaxConcentration);
	DOREPLIFETIME(UNPAttributeSet, AttackPower);
	DOREPLIFETIME(UNPAttributeSet, DefensePower);
	DOREPLIFETIME(UNPAttributeSet, MoveSpeed);
}

bool UNPAttributeSet::PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data)
{
	Super::PreGameplayEffectExecute(Data);

	return true;
}

void UNPAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	float DeltaValue = 0.f;

	//Что это ???
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// Ну тут вообще какая-то херь пошла...
	ANPCharacterBase* TargetCharacter = nullptr;

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* TargetActor = nullptr;
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<ANPCharacterBase>(TargetActor);
	}

	// 26 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Зажатый косинус.)
	//if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	//{
	//	SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));

	//}
}

void UNPAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNPAttributeSet, Health, OldValue);
}

void UNPAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNPAttributeSet, MaxHealth, OldValue);
}

void UNPAttributeSet::OnRep_Concentration(const FGameplayAttributeData& OldValue)
{

}

void UNPAttributeSet::OnRep_MaxConcentration(const FGameplayAttributeData& OldValue)
{

}

void UNPAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{

}

void UNPAttributeSet::OnRep_DefensePower(const FGameplayAttributeData& OldValue)
{

}

void UNPAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldValue)
{

}
