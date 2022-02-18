// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/NPCharacterBase.h"
#include "GameplayEffect.h"

// Sets default values
ANPCharacterBase::ANPCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UNPAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	//Разобраться, как лучше
	//AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

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

// Called every frame
void ANPCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

