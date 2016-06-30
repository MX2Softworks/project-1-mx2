// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GameCharacter.h"
#include "MainCharacter.h"
#include "EngineUtils.h"
#include "BattleManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDefense);

UENUM(BlueprintType)
enum class ECombatPhase : uint8
{
	Decision UMETA(DisplayName="Decision"),
	Action UMETA(DisplayName = "Action"),
	Victory UMETA(DisplayName = "Victory"),
	Defeat UMETA(DisplayName = "Defeat")
};

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

	//set up initial EntitiesComingIn for the prototype
	void DebugSetEntitiesComingIn();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetAttackOccurred(bool bDidAttackOccur);

	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool GetAttackOccurred();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool GetIsPlayerTurn();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetIsPlayerTurn(bool bIsTurnActive);

	UFUNCTION(BlueprintCallable, Category = "Timer")
	void TimerEnd(); 

	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	TArray<AGameCharacter*> GetTurnOrder();

	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	int GetTurnCounter();

	UPROPERTY(BlueprintAssignable)
	FOnDefense OnDefense;

private:

	TArray<AGameCharacter*> EntitiesComingIn;
	TArray<AGameCharacter*> TurnOrder;
	
	UPROPERTY()
	bool bIsPlayerTurnActive = false;

	bool bAttackOccurred = false; 
	bool bCanDisplayMessage = false; 

	int TurnCounter = 0; 
	int RoundCounter = 1; 

	ECombatPhase CombatPhase; 
	
	FTimerHandle LoopTimerHandle;
};
