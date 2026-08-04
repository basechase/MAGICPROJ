// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerClass.h"
#include "ClassSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAGICPROJECT_API UClassSelectionWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void RequestClass(EPlayerClassType RequestedClass);
	
};
