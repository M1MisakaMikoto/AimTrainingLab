// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseCharacter.h"

#include "ABaseWeapon.h"
#include "AbilitySystemComponent.h"
#include "AWeaponDefaultRifle.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UEquipWeaponAbility.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AABaseCharacter::AABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);

	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);

	//赋予能力
    const FGameplayAbilitySpec AbilitySpec(UUEquipWeaponAbility::StaticClass(), 1, 0, this);
	EquipAbilityHandle = AbilitySystemComponent->GiveAbility(AbilitySpec);

	
}

// Called when the game starts or when spawned
void AABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 应用默认 InputMappingContext

	if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultInputContext, 0);
		}
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AABaseCharacter::OnBeginOverlap);
}

void AABaseCharacter::OnMoveInput(const FInputActionValue& InputActionValue)
{
	
	FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementVector.Y);
	
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void AABaseCharacter::OnLookInput(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>() * MouseSensitivity;

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AABaseCharacter::OnFireInput(const FInputActionValue& InputActionValue)
{
	if(EquippedWeapon)
	{
		if(AAWeaponDefaultRifle* Rifle = Cast<AAWeaponDefaultRifle>(EquippedWeapon))
		{
			Rifle->Fire(this);
		}
	}
}

// Called every frame
void AABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABaseCharacter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(AABaseWeapon* Weapon = Cast<AABaseWeapon>(OtherActor))
	{
		TryEquipWeapon(Weapon);
	}
}

// Called to bind functionality to input
void AABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AABaseCharacter::OnMoveInput);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AABaseCharacter::OnLookInput);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AABaseCharacter::OnFireInput);
	}

}

void AABaseCharacter::TryEquipWeapon(AABaseWeapon* WeaponToEquip)
{
	PushPendingEquipWeapon(WeaponToEquip);
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->TryActivateAbility(EquipAbilityHandle);
	}
}

UAbilitySystemComponent* AABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

