// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayAbility.h"

#include "DrawDebugHelpers.h"
#include "Camera/CameraActor.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "ViewportToolbar/UnrealEdViewportToolbar.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

UMyGameplayAbility::UMyGameplayAbility()
{
	
}

void UMyGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* Info,
                                         const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	APlayerController* PC = Cast<APlayerController>(GetActorInfo().PlayerController.Get());
	FRotator CameraRotation = PC->PlayerCameraManager->GetCameraRotation();
	float Pitch = PC->PlayerCameraManager->GetCameraRotation().Pitch;
	ACharacter* Character = Cast<ACharacter>(Info->AvatarActor.Get());
	
	
	FVector StartingCamLocation = PC->PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartingCamLocation + CameraRotation.Vector() * 100000.f;
	
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(Character);
	FHitResult Hit;
	
	
	
	
	Super::ActivateAbility(Handle, Info, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("FIRE ABILITY ACTIVATED"));
	
	if (Character)
	{
		
		bool bHit = GetWorld()->LineTraceSingleByChannel(
			Hit,
			StartingCamLocation,
			EndLocation,
			ECC_Visibility,
			CollisionParams);
			
		FVector TargetLocation = Hit.bBlockingHit ? Hit.Location : EndLocation;
		
		if (bHit)
		{
			
			
			
			
			
			
			DrawDebugLine(
	GetWorld(),
StartingCamLocation,
		Hit.Location,
		FColor::Green,
		false,
10.0f,
0,
1.0f);
			
			
		DrawDebugLine(
	GetWorld(),
	Hit.Location,
	EndLocation,
	FColor::Red,
	false,
	10.0f,
	0,
	1.0f);
		
		}
		FVector Direction = (TargetLocation - Character->GetActorLocation()).GetSafeNormal();
		FRotator SpawnRotation = Direction.Rotation();
		
		GetWorld()->SpawnActor<AActor>(
			BulletActor,
			Character->GetActorLocation() + Character->GetActorForwardVector() * 200.f,
			FRotator(SpawnRotation.Pitch, SpawnRotation.Yaw, 0.0f));
		
	}
	
	
}
