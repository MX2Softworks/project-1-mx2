// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "MainCharacter.h"

//setter and getter for current fear
float AMainCharacter::GetCurrentFear(){ return CurrentFear; }
void AMainCharacter::SetCurrentFear(float NewFear){ CurrentFear = NewFear; }

//setter and getter for max fear
void AMainCharacter::SetMaxFear(float NewFear){ MaxFear = NewFear; }
float AMainCharacter::GetMaxFear(){ return MaxFear; }

//resets the current fear to the max fear. 
void AMainCharacter::ResetFear() {

	CurrentFear = MaxFear; 
	return; 
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	MaxFear = 7; 
	CurrentFear = MaxFear; 
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}