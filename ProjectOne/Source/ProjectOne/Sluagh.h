// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mob.h"
#include "Sluagh.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTONE_API ASluagh : public AMob
{
	GENERATED_BODY()

public:
	
	// Sets default values for this pawn's properties
	ASluagh(); 

	//Attack function which creates the soul orb pattern depending on the attack
	virtual bool Attack() override; 
	
	//Called when the timer ends to set the IsAttacking flag to false
	UFUNCTION(BlueprintCallable, Category = "Timer")
	void AttackTimerEnd();

	//Returns the duration of the first attack
	UFUNCTION(BlueprintCallable, Category = "Attack")
	float GetAttackTime_1();

	//Can be used to change the duration of the first attack, not recommended 
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetAttackTime_1(float NewAttackTime); 


private: 

	//Timer used to reset the IsAttacking flag
	FTimerHandle LoopTimerHandle;

	//Used to store the duration of the first attack. 
	UPROPERTY(EditAnywhere)
	float AttackTime_1;
	
};
