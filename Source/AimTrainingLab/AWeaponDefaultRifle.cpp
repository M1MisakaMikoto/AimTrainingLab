// Fill out your copyright notice in the Description page of Project Settings.


#include "AWeaponDefaultRifle.h"

#include "ABaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"

AAWeaponDefaultRifle::AAWeaponDefaultRifle()
{
	MeshComponent->SetCollisionProfileName(TEXT("Items"));
}

void AAWeaponDefaultRifle::Use()
{
	Super::Use();
	
}

void AAWeaponDefaultRifle::Fire(AActor* AvatarActor)
{
	Use();
	if(AABaseCharacter* Character = Cast<AABaseCharacter>(AvatarActor))
	{
		FVector3f StartPoint(Character->GetCameraComponent()->GetComponentLocation());
		FVector3f DetectDirection(Character->GetCameraComponent()->GetComponentRotation().Vector());
		FVector3f EndPoint(StartPoint + DetectDirection * 1000);
		
	}

}
