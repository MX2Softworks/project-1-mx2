// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "Reticle.h"


// Sets default values
AReticle::AReticle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ReticleBase"));
	}

	ReticleSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ReticleSprite"));
	ReticleSprite->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AReticle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReticle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AReticle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

