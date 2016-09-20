// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"
#include "Weapon.h"
#include "Melee.h"
#include "MainCharacter.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTONE_API AMainCharacter : public AGameCharacter
{
	GENERATED_BODY()
	
public:
	
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category="Fear")
	void SetCurrentFear(float NewFear);

	UFUNCTION(BlueprintCallable, Category="Fear")
	float GetCurrentFear();

	UFUNCTION(BlueprintCallable, Category="Fear")
	void SetMaxFear(float NewFear);

	UFUNCTION(BlueprintCallable, Category="Fear")
	float GetMaxFear();

	UFUNCTION(BlueprintCallable, Category="Fear")
	void ResetFear(); 

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugMakeMeleeWeapon(); 

private:

	float CurrentFear; 
	float MaxFear;
};
