// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectOne.h"
#include "BattleManager.h"


// Sets default values for this component's properties
UBattleManager::UBattleManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;


	EntitiesComingIn.Init(nullptr, 2);
	EntitiesComingIn[0];

	if (!GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("No World"));
	}
	else
	{
		if (GetWorld() && GetWorld()->GetFirstPlayerController())
		{
			UE_LOG(LogTemp, Warning, TEXT("got player controller successfully"));
		}
		else 
		{
			UE_LOG(LogTemp, Error, TEXT("World exists. But no player controller."));
		}
		
	}
}

//TODO: Implement Engagement System
//Constructor that will take an array of actors in combat to create the turn order. 
UBattleManager::UBattleManager(TArray<AGameCharacter*> EntitiesInCombat) 
{

	// ...

}


//Getter and Setter for bAttackOccurred
void UBattleManager::SetAttackOccurred(bool bDidAttackOccur) { bAttackOccurred = bDidAttackOccur; }
bool UBattleManager::GetAttackOccurred() { return bAttackOccurred; }

//Getter for EntitesComingIn
TArray<AGameCharacter*> UBattleManager::GetEntitiesComingIn(){ return EntitiesComingIn; }

//Getter and Setter for bIsPlayerTurnActive
void UBattleManager::SetIsPlayerTurn(bool bIsTurnActive) { bIsPlayerTurnActive = bIsTurnActive; }
bool UBattleManager::GetIsPlayerTurn() { return bIsPlayerTurnActive; }

// Getter and Setter for bAttackOccurredBP
void UBattleManager::SetAttackOccurredBP(bool bDidAttackOccurBP) { bAttackOccurredBP = bDidAttackOccurBP; }
bool UBattleManager::GetAttackOccurredBP() { return bAttackOccurredBP; }

//Getter for TurnOrder
TArray<AGameCharacter*> UBattleManager::GetTurnOrder() { return TurnOrder; };

//Getter for TurnOrderWidgetArray
TArray<AGameCharacter*> UBattleManager::GetTurnOrderWidgetArray() { return TurnOrderWidgetArray; };

//Getter for TurnCounter
int32 UBattleManager::GetTurnCounter() { return TurnCounter; };

//TODO: Make this work with the Engagement System
/*
	1) creates a turn order array initially of size 22 (the maximum number of entities in combat given 3 panes with 6 locations each and 4 players.
	2) Goes through each entity coming in and places them in the turn order array according to their speed, if an index is occupied, the entity is added
	   after the index. 
*/
TArray<AGameCharacter*> UBattleManager::CalculateTurnOrder()
{
	//makes a 2d timeline where each frame is the entities that go during that time.
	int32 EntitySpeed = 0; 
	TurnOrder.Reset(1);
	for (AGameCharacter* Entity : EntitiesComingIn)
	{
		if (Entity != nullptr)
		{
			EntitySpeed = Entity->GetSpeed(); 
			if (RoundCounter % EntitySpeed == 0)
			{
				TurnOrder.Emplace(Entity);
				GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Yellow, FString::Printf(TEXT("Added %s"), *Entity->GetName()));
			}
		}
	}
	TurnOrder.Add(nullptr); 
	return TurnOrder; 
}

//set up initial EntitiesComingIn for the prototype
void UBattleManager::DebugSetEntitiesComingIn()
{
	
	//uses an actor iterator over the level to grab every actor and place them in the array. 
	TActorIterator<AGameCharacter> ActorItr(GetWorld());

	for(ActorItr; ActorItr; ++ActorItr)
	{
		AGameCharacter *Entity = *ActorItr;
		if (Entity)
		{
			EntitiesComingIn.AddUnique(Entity);
		}
	} 
}

//this function is used to create a timer for message output to screen when another entity attacks besides the player.
//this function is internal and is called using the settimer function. 
void UBattleManager::TimerEnd()
{ 
	bCanDisplayMessage = true; 
}

// Called when the game starts
void UBattleManager::BeginPlay()
{
	Super::BeginPlay();
	DebugSetEntitiesComingIn();
	TurnOrder.Init(nullptr, 1); 
	TurnOrderWidgetArray.Init(nullptr, 1);
	CalculateTurnOrder();
	PopulateTurnOrderWidgetArray();

	//initialize our combat phase. 
	CombatPhase = ECombatPhase::Preparation;

	//initialize our timer. 
	GetWorld()->GetTimerManager().SetTimer(LoopTimerHandle, this, &UBattleManager::TimerEnd, 1.f, false);
}

//this function is called inside the tick component to do the reptitive operations of incrimenting turn order and checking to see if its a new round
void UBattleManager::NextTurn()
{
	TurnCounter++;
	if (TurnCounter >= TurnOrder.Num())
	{
		RoundCounter++;
		TurnCounter = 0; 
		CalculateTurnOrder(); ///recalculates turn order
		CombatPhase = ECombatPhase::Preparation;
		return;
	}
	else
	{
		CombatPhase = ECombatPhase::Preparation;
		return;
	}
}

//this function is called every turn to make sure the turn order widget always has atleast 6 entites for its display, even if it means calculating forward rounds.
TArray<AGameCharacter*> UBattleManager::PopulateTurnOrderWidgetArray()
{
	TurnOrderWidgetArray.Reset(1);
	TurnOrderWidgetArray.Init(nullptr, 7);

	int32 TempTurnCounter = TurnCounter; 
	int32 TempRoundCounter = RoundCounter;
	int32 Index = 0; 
	while (TempTurnCounter < TurnOrder.Num() && Index < 7)
	{
		AGameCharacter* Entity = TurnOrder[TempTurnCounter];
		if (Entity)
		{
			TurnOrderWidgetArray[Index] = Entity;
			Index++;
		}
		TempTurnCounter++;
	}

	while (Index < 7)
	{
		int32 EntitySpeed = 0;
		TempRoundCounter++; 
		for (AGameCharacter* Entity : EntitiesComingIn)
		{
			if (Entity != nullptr)
			{
				EntitySpeed = Entity->GetSpeed();
				if (TempRoundCounter % EntitySpeed == 0)
				{
					if (TurnOrderWidgetArray.IsValidIndex(Index))
					{
						TurnOrderWidgetArray[Index] = Entity;
						Index++;
					}
					
				}
			}
		}
	}
	return TurnOrderWidgetArray;
}

// Called every frame
void UBattleManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );


	//short circuit the round counter for the prototype to stop after first round. 
	if (RoundCounter >= 20)
	{
		return;
	}
	
	//On each turn, the switch statement selects the current character in the turn order, prepares their state and then 
	//executes their action. Currently in the prototype, names are used to find entities, but in the future some other implementation will be used. 
	switch (CombatPhase)
	{

		/* the decision phase is when characters will make decisions for their turn: 
			1)	The round and entity are displayed during this phase 
			2)  The combat phase is switched to the action phase of the character 
			
		*/
		
		case ECombatPhase::Preparation:

			if (TurnOrder.IsValidIndex(TurnCounter) && TurnOrder[TurnCounter] != nullptr)
			{
				//displays a message about the round and entity to the log
				UE_LOG(LogTemp, Warning, TEXT("Round: %d\tEntity: %s"), RoundCounter, *TurnOrder[TurnCounter]->GetName());

				PopulateTurnOrderWidgetArray(); 

				//uses timer in the event that entity deciding is a sluagh to display a message after a delay.
				if(Cast<AMob>(TurnOrder[TurnCounter]))
				{
					//resets the timer
					GetWorld()->GetTimerManager().SetTimer(LoopTimerHandle, this, &UBattleManager::TimerEnd, 1.f, false);
					UE_LOG(LogTemp, Warning, TEXT("Sluagh Timer Active."));

				}
				//resets the current fear timer of Beck so that he has full time at the beginning of the round. 
				else if (Cast<AMainCharacter>(TurnOrder[TurnCounter]))
				{
					AMainCharacter* MC = Cast<AMainCharacter>(TurnOrder[TurnCounter]); 
					check(MC);
					MC->ResetFear();	
					///switch gamestate to Attack
				}
			}
			CombatPhase = ECombatPhase::Action;
			break;

		/*
			During this phase of combat: 
			1)		if the player is the one going, their fear will act a timer for their turn. The action phase waits for a 
					response from the player before it finishes or waits until the timer reaches 0. 
			2)		If the slaugh is the one going, the phase waits until the message can be displayed and the timer runs out 
					before spawning an OrbPattern. While the OrbPattern is active the sluagh waits, and once it finishes, the sluagh
					ends its turn. 
		*/

		case ECombatPhase::Action:
			if (TurnOrder.IsValidIndex(TurnCounter) && TurnOrder[TurnCounter] != nullptr)
			{	
				///debug logic to give beck a turn in combat allowing him to make a move. 
				if(Cast<AMainCharacter>(TurnOrder[TurnCounter]))
				{
					//cast Beck to a main character to make fear available. 
					AMainCharacter* MC = Cast<AMainCharacter>(TurnOrder[TurnCounter]);
					check(MC);
					
					//checks to see if an attack occurred or the fear timer ended to end the turn
					if (MC->GetCurrentFear() <= 0 || bAttackOccurred == true)
					{
						//resets the sluagh's message timer
						bCanDisplayMessage = false;
					
						//ends turn.
						NextTurn();
						bAttackOccurred = false;
						bIsPlayerTurnActive = false;

						bAttackOccurredBP = true;
						break; 
					}

					//otherwise if the turn is still going, decriments the character's fear by delta time
					MC->SetCurrentFear(MC->GetCurrentFear() - DeltaTime);
					bIsPlayerTurnActive = true; 
					break; 
				}

				///if the entity is a sluagh
				else if(Cast<AMob>(TurnOrder[TurnCounter]))
				{
					//if the message timer has ended and it does not have to wait for an attack to finish, the sluagh will 
					//initiate its first attack. 
					if (bCanDisplayMessage && bWaitForAttackToFinish == false)
					{
						//resets 
						bAttackOccurred = false; 

						//attack 
						TurnOrder[TurnCounter]->Attack();
						bAttackOccurred = TurnOrder[TurnCounter]->GetIsAttacking(); 
						bWaitForAttackToFinish = true; 
					}
					//assuming an attack has already been initiated, when the sluagh's attack ends, it will stop waiting and end its turn. 
					if (bWaitForAttackToFinish == true && TurnOrder[TurnCounter]->GetIsAttacking() == false)
					{
						//reset for the next turn
						bAttackOccurred = false;
						bWaitForAttackToFinish = false;
						bCanDisplayMessage = false;

						//used to expose attack occurrence to turn order
						bAttackOccurredBP = true; 
						GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Green, FString::Printf(TEXT("Attack Finished")));
						NextTurn();
						break;
					}
					
					//if the orb pattern animation is currently playing or the sluagh is waiting for the message timer to end. 
					else
					{
						break;
					}
				}
			}

			//if the current character is null, move to the next character's turn. 
			NextTurn(); 
			break;
			
		case ECombatPhase::Defeat:
			break;

		case ECombatPhase::Victory:
			break;
	}

	
}

