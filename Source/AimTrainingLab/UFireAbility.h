// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "UFireAbility.generated.h"

/**
 *  Fire Ability是属于武器的能力 武器拥有开火的能力 人物拥有使用道具的能力
 */
UCLASS()
class AIMTRAININGLAB_API UUFireAbility : public UGameplayAbility
{
	GENERATED_BODY()


public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
};
