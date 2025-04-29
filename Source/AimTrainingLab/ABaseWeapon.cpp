// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseWeapon.h"

#include "Components/BoxComponent.h"

// Sets default values
AABaseWeapon::AABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(SceneComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	BoxCollisionComponent->SetupAttachment(SceneComponent);
	BoxCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

}

// Called when the game starts or when spawned
void AABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABaseWeapon::Use()
{
	
}

