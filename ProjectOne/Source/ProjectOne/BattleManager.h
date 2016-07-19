// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GameCharacter.h"
#include "MainCharacter.h"
#include "EngineUtils.h"
#include "BattleManager.generated.h"

UENUM(BlueprintType)
enum class ECombatPhase : uint8
{
	Preparation UMETA(DisplayName="Decision"),
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
	
	//will be used in the future to initialize EntitiesComingIn array
	UBattleManager(TArray<AGameCharacter*> EntitiesInCombat);

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	TArray<AGameCharacter*> InitializeTurnOrder();

	//set up initial EntitiesComingIn for the prototype
	void DebugSetEntitiesComingIn();


	//attack occurred is used in the battle manager's tick function to figure out whether an attack was initiated. 
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetAttackOccurred(bool bDidAttackOccur);
	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool GetAttackOccurred();

	//a function written to attempt to delegate turn order initialization to the battlegamemode_BP blueprint. 
	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	TArray<AGameCharacter*> GetEntitiesComingIn();

	//is player turn is used in teh battle manager's tick function to figure out whether its the player's turn or not. 
	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool GetIsPlayerTurn();
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetIsPlayerTurn(bool bIsTurnActive);

	//this function is used as a message timer to create a delay between the end of the player's turn and the beginning of the enemy's
	UFUNCTION(BlueprintCallable, Category = "Timer")
	void TimerEnd(); 

	//this function returns the turn order of the characters in combat. 
	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	TArray<AGameCharacter*> GetTurnOrder();

	//this function returns the turn counter variable which is used as index of the turn order
	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	int32 GetTurnCounter();

	//these functions are used by the turn order widget to animate
	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	void SetAttackOccurredBP(bool bDidAttackOccurBP);
	UFUNCTION(BlueprintCallable, Category = "Turn Order")
	bool GetAttackOccurredBP();

private:

	//a list of characters entering combat
	TArray<AGameCharacter*> EntitiesComingIn;

	//a list of characters in order of when they go in combat
	TArray<AGameCharacter*> TurnOrder;
	
	//used to determine whether it is the player's turn or not
	UPROPERTY()
	bool bIsPlayerTurnActive = false;

	//used to determine whether an attack occurred for the turn order widget
	bool bAttackOccurredBP = false;

	//used to determine whether an attack was initiated and the orb pattern was spawned
	bool bAttackOccurred = false; 

	//used to determine whether the manager should wait for the orb pattern to finish
	bool bWaitForAttackToFinish = false;

	//used to determine whether the enemy can act
	bool bCanDisplayMessage = false; 

	//used as an index in the turnOrder TArray to keep track of who's turn it is. 
	int32 TurnCounter = 0; 

	//a derived counter used to keep track of how many times through the array the manager has looped through
	int32 RoundCounter = 1; 

	//an enumerated type used to determine the combat phase 
	ECombatPhase CombatPhase; 
	
	//a timer handle used to create a delay for the enemy's action
	FTimerHandle LoopTimerHandle;
};
