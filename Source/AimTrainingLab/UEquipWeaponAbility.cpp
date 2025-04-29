// Fill out your copyright notice in the Description page of Project Settings.


#include "UEquipWeaponAbility.h"

#include "ABaseCharacter.h"
#include "ABaseWeapon.h"

void UUEquipWeaponAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if(!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		UE_LOG(LogTemp, Warning, TEXT("[Warning]Equip Weapon Ability Activate Failed Because of CommitAbility return false"));
		CancelAbility(Handle, ActorInfo, ActivationInfo, true);
		return;
	}

	AABaseCharacter* Character = Cast<AABaseCharacter>(ActorInfo->AvatarActor.Get());

	AABaseWeapon* WeaponToEquip = Character->PopPendingEquipWeapon();
	
	if(Character && WeaponToEquip)
	{
		Character->SetEquippedWeapon(WeaponToEquip);
		//WeaponToEquip->GetRootComponent()->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("WeaponSocket"));
		WeaponToEquip->SetOwner(Character);
		
		UE_LOG(LogTemp, Display, TEXT("[INFO]Equipped Weapon: %s"), *WeaponToEquip->GetName());
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("[ERROR]Weapon Equip Failed! Character: %s Weapon: %s"), Character ? *Character->GetName() : TEXT("nullptr"), WeaponToEquip ? *WeaponToEquip->GetName() : TEXT("nullptr"));
	}
	
}
