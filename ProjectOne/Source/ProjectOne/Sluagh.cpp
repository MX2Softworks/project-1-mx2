// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "Sluagh.h"


ASluagh::ASluagh()
{
	
}

//Getters and setters for AttackTime_1
float ASluagh::GetAttackTime_1(){ return AttackTime_1; }
void  ASluagh::SetAttackTime_1(float NewAttackTime_1){ AttackTime_1 = NewAttackTime_1; }

//Called when the timer ends to set the IsAttacking flag to false
void ASluagh::AttackTimerEnd()
{
	SetIsAttacking(false);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Attack Timer Up.")));
	}
}

//inherited function from GameCharacter
bool ASluagh::Attack()
{ 
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%s Attacks!"), *this->GetName()));
	}

	//Orb Pattern spawning and setting AttackTime_1 is handled in the blueprint 'AttackBroadcaster_BP' by the event delegate
	OnAttack_1.Broadcast(); 

	//raise the flag and start the timer to let the Orb Pattern play out
	SetIsAttacking(true); 
	GetWorld()->GetTimerManager().SetTimer(LoopTimerHandle, this, &ASluagh::AttackTimerEnd, AttackTime_1, false);
	return true; 
}


