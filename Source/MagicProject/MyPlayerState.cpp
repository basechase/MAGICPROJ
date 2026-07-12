// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "AbilitySystemComponent.h"
#include "MyGameplayAbility.h"

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

AMyPlayerState::AMyPlayerState()
{
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(
		TEXT("AbilitySystemComponent"));
	
	AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(UMyGameplayAbility::StaticClass(), 1));
	
}
