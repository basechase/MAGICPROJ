// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "AbilitySystemComponent.h"
#include "MyGameplayAbility.h"

void AMyPlayerState::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerState BeginPlay"));

	UE_LOG(LogTemp, Warning, TEXT("Startup Ability Count: %d"), StartupAbilities.Num());

		for (const TSubclassOf<UGameplayAbility>& Ability : StartupAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1));
		
			UE_LOG(LogTemp, Warning, TEXT("Granted Ability: %s"), *Ability->GetName());
		}
	
	
}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

AMyPlayerState::AMyPlayerState()
{
	UE_LOG(LogTemp, Warning, TEXT("C++ Constructor Running"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(
		TEXT("AbilitySystemComponent"));
	
	
	
	
	
}
