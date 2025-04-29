// Fill out your copyright notice in the Description page of Project Settings.


#include "ATarget.h"

// Sets default values
AATarget::AATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	MeshComponent->SetupAttachment(SceneComponent);

}

// Called when the game starts or when spawned
void AATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

