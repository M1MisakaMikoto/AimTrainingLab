// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABaseWeapon.generated.h"

UCLASS()
class AIMTRAININGLAB_API AABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupMeshComponent(){};

	virtual void SetupCollisionComponent(float SphereRadius){};

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	USceneComponent* SceneComponent;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	class UBoxComponent* BoxCollisionComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Use();
};
