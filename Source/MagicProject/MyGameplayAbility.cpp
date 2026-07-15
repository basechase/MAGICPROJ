// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayAbility.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "ViewportToolbar/UnrealEdViewportToolbar.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

UMyGameplayAbility::UMyGameplayAbility()
{
	ActorOffSet = FVector(100.0f, 0.0f, 0.0f); 
}

void UMyGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* Info,
                                         const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	ACharacter* Character = Cast<ACharacter>(Info->AvatarActor.Get());
	Super::ActivateAbility(Handle, Info, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("FIRE ABILITY ACTIVATED"));
	
	if (Character)
	{
		DrawDebugSphere(Character->GetWorld(), Character->GetActorLocation(), 16, 16, FColor::Green, false, 3.0f);
		GetWorld()->SpawnActor<AActor>(BulletActor, Character->GetActorLocation()+ Character->GetActorForwardVector()* 200, Character->GetActorRotation());
	}
	
	
}
