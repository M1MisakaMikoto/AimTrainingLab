// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ALabPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AIMTRAININGLAB_API AALabPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TSoftObjectPtr<class UInputMappingContext> DefaultInputContext;
};
