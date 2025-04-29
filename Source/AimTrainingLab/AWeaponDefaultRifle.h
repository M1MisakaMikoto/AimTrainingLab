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

public:
	void Fire(AActor* AvatarActor);
};
