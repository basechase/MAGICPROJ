// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

/**
 * 
 */

	UENUM(BlueprintType)
	enum class EPlayerClassType : uint8
	{
		None UMETA(DisplayName = "None"),
		Red UMETA(DisplayName = "Red/Fire"),
		Blue UMETA(DisplayName = "Blue/Ice"),
		Purple UMETA(DisplayName = "Purple/Necro"),
		Green UMETA(DisplayName = "Green/Earth")
	};
	
	
	

