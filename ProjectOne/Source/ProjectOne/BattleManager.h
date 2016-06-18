// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GameCharacter.h"
#include "EngineUtils.h"
#include "BattleManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTONE_API UBattleManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBattleManager();

	UBattleManager(TArray<AGameCharacter*> EntitiesInCombat);
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	TArray<AGameCharacter*> InitializeTurnOrder();

private:

	TArray<AGameCharacter*> EntitiesComingIn;
	TArray<AGameCharacter*> TurnOrder;
	
};
