// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTONE_API AEnemy : public AGameCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	int32 GetPreferredPane();
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	void SetPreferredPane(int32 bPreferredPane);

private:

	// The number pane this enemy should be placed on
	int32 PreferredPane;

};
