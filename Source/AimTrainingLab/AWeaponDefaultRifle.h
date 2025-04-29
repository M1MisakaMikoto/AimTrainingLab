// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABaseWeapon.h"
#include "AWeaponDefaultRifle.generated.h"

/**
 * 
 */
UCLASS()
class AIMTRAININGLAB_API AAWeaponDefaultRifle : public AABaseWeapon
{
	GENERATED_BODY()
	
public:
	AAWeaponDefaultRifle();

protected:
	virtual void Use() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	float FireCooldownTime = 0.2f;

	UPROPERTY(BlueprintReadOnly, Category="Weapon")
	float FireCooldownTimer = 0.0f;

public:
	void Fire(AActor* AvatarActor);
};
