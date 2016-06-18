// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "GameCharacter.h"


// Sets default values
AGameCharacter::AGameCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 4; 
}

int   AGameCharacter::GetSpeed(){ return Speed; }
void  AGameCharacter::SetSpeed(int NewSpeed) { Speed = NewSpeed; }

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGameCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

