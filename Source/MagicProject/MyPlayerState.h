// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MAGICPROJECT_API AMyPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	
public:
	
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	
	AMyPlayerState();
};
