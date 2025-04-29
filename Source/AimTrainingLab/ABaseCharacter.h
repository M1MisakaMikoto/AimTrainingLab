// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpecHandle.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "ABaseCharacter.generated.h"

UCLASS()
class AIMTRAININGLAB_API AABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnMoveInput(const FInputActionValue& InputActionValue);

	void OnLookInput(const FInputActionValue& InputActionValue);

	void OnFireInput(const FInputActionValue& InputActionValue);
	
	UPROPERTY(BlueprintReadOnly, Category="AbilitySpecHandles")
	FGameplayAbilitySpecHandle EquipAbilityHandle;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Gameplay Ability System -------------------------------------------------------------- start
	// ASC接口实现
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	// ASC
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAbilitySystemComponent* AbilitySystemComponent;
	
	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* CameraComponent;
	UFUNCTION(BlueprintCallable, category = "Camera")
	UCameraComponent* GetCameraComponent() const {return CameraComponent;}
	
	// Abilities
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGameplayAbility> FireAbility;

	// Gameplay Ability System -------------------------------------------------------------- end
	// Inputs ------------------------------------------------------------------------------ start

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Input Mapping Context
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* DefaultInputContext;
	
	// Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* FireAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	float MouseSensitivity = 1.0f;
	// Inputs ------------------------------------------------------------------------------ end

	UFUNCTION(BlueprintCallable, category = "Weapon")
	void TryEquipWeapon(class AABaseWeapon* WeaponToEquip);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	class AABaseWeapon* PendingEquipWeapon;
public:
	UFUNCTION(BlueprintCallable, category = "Weapon")
	void PushPendingEquipWeapon(class AABaseWeapon* WeaponToEquip)
	{
		PendingEquipWeapon = WeaponToEquip;
	};
	UFUNCTION(BlueprintCallable, category = "Weapon")
	AABaseWeapon* PopPendingEquipWeapon()
	{
		if (!PendingEquipWeapon)
		{
			return nullptr;
		}
		AABaseWeapon* temp = PendingEquipWeapon;
		PendingEquipWeapon = nullptr;
		return temp;
	};
private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	class AABaseWeapon* EquippedWeapon;
public:
	UFUNCTION(BlueprintCallable, category = "Weapon")
	AABaseWeapon* GetEquippedWeapon()
	{
		return EquippedWeapon;
	}
	UFUNCTION(BlueprintCallable, category = "Weapon")
	void SetEquippedWeapon(AABaseWeapon* WeaponToEquip)
	{
		EquippedWeapon = WeaponToEquip;
	}

	

};
