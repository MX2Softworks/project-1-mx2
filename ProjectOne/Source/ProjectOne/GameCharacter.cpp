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

int32   AGameCharacter::GetSpeed(){ return Speed; }
void  AGameCharacter::SetSpeed(int32 NewSpeed) { Speed = NewSpeed; }
bool  AGameCharacter::GetIsAttacking() { return bIsAttacking; }
void  AGameCharacter::SetIsAttacking(bool IsAttacking) { bIsAttacking = IsAttacking; }


//Debug function called to get entities to attack in the combat prototype.
bool AGameCharacter::Attack()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%s Attacks!"), *this->GetName()));
	}
	OnAttack_1.Broadcast(); 
	bIsAttacking = true; 
	return true;
}


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

