// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATarget.generated.h"

UCLASS()
class AIMTRAININGLAB_API AATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category="Target")
	USceneComponent* SceneComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Target")
	UStaticMeshComponent* MeshComponent;
	
};
