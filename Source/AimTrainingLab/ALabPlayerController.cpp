// Fill out your copyright notice in the Description page of Project Settings.


#include "ALabPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


void AALabPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
		Subsystem->AddMappingContext(DefaultInputContext.LoadSynchronous(), 0);
	}
}
