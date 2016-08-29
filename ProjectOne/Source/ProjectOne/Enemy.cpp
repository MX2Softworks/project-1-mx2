// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "Enemy.h"


// Getter and Setter for bPreferredPane
int32 AEnemy::GetPreferredPane() { return PreferredPane; }
void AEnemy::SetPreferredPane(int32 bPreferredPane) { PreferredPane = bPreferredPane; }