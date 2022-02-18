// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/NPAttributeSet.h"

UNPAttributeSet::UNPAttributeSet()
{

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

void UNPAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{

}

void UNPAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{

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
