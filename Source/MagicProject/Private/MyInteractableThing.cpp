// Fill out your copyright notice in the Description page of Project Settings.


#include "public/MyInteractableThing.h"

// Sets default values
AMyInteractableThing::AMyInteractableThing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyInteractableThing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyInteractableThing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyInteractableThing::ActivateBox_Implementation()
{
}

