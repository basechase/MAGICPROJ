// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MyPlayerState.h"
#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "MagicProjectCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AMagicProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
protected:

	/** Jump Input Action */
	
	//shoulder swapping lik arc raiders :)
	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* SwapAction;
	
	//left click
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LeftAction;

	//right click
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RightAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;
	
	

public:
	
	/** Constructor */
	AMagicProjectCharacter();	

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

public:

	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	TSubclassOf<UGameplayAbility> FireAbilityClass;
	
	
	/* Ability System Getter */
	UAbilitySystemComponent* GetAbilitySystemComponent() const  { return AbilitySystemComponent; }
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	
	/** server calls for player state  */
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();
	
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoAim(const FInputActionValue& Value);
	
	UFUNCTION(BlueprintCallable, Category="Input")
	void DoClick(const FInputActionValue& Value);
	
	virtual void DoRelease(const FInputActionValue& Value);
	
	UFUNCTION(BlueprintCallable, Category="Input")
	void DoShoulderSwap(const FInputActionValue& Value);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float CameraLerpSpeed =  0.5f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector DefaultCameraOffset =FVector(0.0f, 0.0f, 0.0f);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector AimCameraOffset = FVector(50,60,20);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsAiming = false;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bRightShoulder = true;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> CrosshairWidgetClass;
	
	UPROPERTY()
	UUserWidget* CrosshairWidget;
	
	
public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

