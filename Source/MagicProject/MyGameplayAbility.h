// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MyGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MAGICPROJECT_API UMyGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	
	UMyGameplayAbility();
	
public:
	
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<class AActor> BulletActor;
	
	
protected:
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
								const FGameplayAbilityActorInfo* Info, 
								const FGameplayAbilityActivationInfo ActivationInfo, 
								const FGameplayEventData* TriggerEventData) 
								override;
	
	
	
	
};
