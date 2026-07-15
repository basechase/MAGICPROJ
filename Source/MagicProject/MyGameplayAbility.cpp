// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayAbility.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "ViewportToolbar/UnrealEdViewportToolbar.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

void UMyGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* Info,
                                         const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, Info, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("FIRE ABILITY ACTIVATED"));
	ACharacter* Character = Cast<ACharacter>(Info->AvatarActor.Get());
	
	if (Character)
	{
		DrawDebugSphere(Character->GetWorld(), Character->GetActorLocation(), 16, 16, FColor::Green, false, 3.0f);
		GetWorld()->SpawnActor<AActor>(BulletActor, Character->GetActorLocation(), Character->GetActorRotation());
	}
	
	
}
