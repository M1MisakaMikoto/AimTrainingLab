// Fill out your copyright notice in the Description page of Project Settings.


#include "AWeaponDefaultRifle.h"

#include "ABaseCharacter.h"
#include "ATarget.h"
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

void AAWeaponDefaultRifle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(FireCooldownTimer > 0.f)
	{
		FireCooldownTimer -= DeltaSeconds;
	}
}

void AAWeaponDefaultRifle::Fire(AActor* AvatarActor)
{

	if(FireCooldownTimer > 0.f)
	{
		return;
	}
	
	Use();
	if(AABaseCharacter* Character = Cast<AABaseCharacter>(AvatarActor))
	{
		if(UWorld* World = GetWorld())
		{
			FVector StartPoint(Character->GetCameraComponent()->GetComponentLocation());
			FVector DetectDirection(Character->GetCameraComponent()->GetComponentRotation().Vector());
			FVector EndPoint(StartPoint + DetectDirection * 5000);
			
			FHitResult HitResult;
			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(Character);

			const bool bHit = World->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECC_Visibility, CollisionParams);

			DrawDebugLine(World, StartPoint, EndPoint, FColor::Red, false, 5.f);

			if(bHit)
			{
				if(AATarget* Target = Cast<AATarget>(HitResult.GetActor()))
				{
					if(GEngine)
					{
						GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Hit Target: %s"), *Target->GetName()));
					}
				}
			}

			FireCooldownTimer = FireCooldownTime;
			
		}
		
	}

}
