// Fill out your copyright notice in the Description page of Project Settings.


#include "UFireAbility.h"

#include "ABaseWeapon.h"
#include "AWeaponDefaultRifle.h"

void UUFireAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                    const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Warning]Fire Ability Activate Failed Because of CommitAbility return false"));
		
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	if(AAWeaponDefaultRifle* DefaultRifle = Cast<AAWeaponDefaultRifle>(ActorInfo->AvatarActor.Get()))
	{
		DefaultRifle->Fire();
	}
	
}
