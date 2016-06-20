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
		UE_LOG(LogTemp, Error, TEXT("No WOrld"));
	}
	else
	{
		if (GetWorld() && GetWorld()->GetFirstPlayerController())
		{
			//EntitiesComingIn[0] = GetWorld()->GetFirstPlayerController();
			UE_LOG(LogTemp, Warning, TEXT("got player controller successfully"));
		}
		else 
		{
			UE_LOG(LogTemp, Error, TEXT("World exists. But no player controller."));
		}
		
	}


	//TODO: Use Actor Iterator to get two of the actors in the world and use them to test the battle system. 
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

//TODO: Make this work with the Engagement System
TArray<AGameCharacter*> UBattleManager::InitializeTurnOrder()
{
	//Initialize TArray of size 10 to nullptr
	//For each entity reference:
		//get the speed
		//for each index of the turn order array:
			//if index % speed is 0 insert reference into index
		
	//return initialized TurnOrderList

	TurnOrder.Init(nullptr, 22);
	int EntitySpeed; 
	for (AGameCharacter* Entity : EntitiesComingIn)
	{
		if (Entity != nullptr)
		{
			EntitySpeed = Entity->GetSpeed(); 
			for (int Index = 0; Index < TurnOrder.Num(); Index++)
			{
				if (Index%EntitySpeed == 0)
				{
					if (TurnOrder[Index] == nullptr){TurnOrder[Index] = Entity;}
					else{TurnOrder.Insert(Entity, Index + 1);}
				}
			}
		}
	}
	return TurnOrder; 
}

//set up initial EntitiesComingIn for the prototype
void UBattleManager::DebugSetEntitiesComingIn()
{
	
	//uses an actor iterator over the level to grab every actor and place them in the array. 
	int EntityIndex = 0;
	TActorIterator<AGameCharacter> ActorItr(GetWorld());

	for(ActorItr; ActorItr; ++ActorItr)
	{
		
		if (EntityIndex < EntitiesComingIn.Num())
		{
			AGameCharacter *Entity = *ActorItr;
			if (Entity)
			{
				EntitiesComingIn[EntityIndex] = Entity;
			}
			EntityIndex++;
		}
	} 
}

// Called when the game starts
void UBattleManager::BeginPlay()
{
	Super::BeginPlay();

	DebugSetEntitiesComingIn();
	InitializeTurnOrder(); 
	CombatPhase = ECombatPhase::Decision;
}

// Called every frame
void UBattleManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (RoundCounter >= 5)
	{
		return;
	}
	switch (CombatPhase)
	{
		case ECombatPhase::Decision:

			if (TurnOrder[TurnCounter] != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Round: %d\tEntity: %s"), RoundCounter, *TurnOrder[TurnCounter]->GetName());
			}
			CombatPhase = ECombatPhase::Action;
			break;

		case ECombatPhase::Action:
			if (TurnOrder[TurnCounter] != nullptr)
			{	
				//debug logic to give beck a turn in combat allowing him to make a move. 
				if (TurnOrder[TurnCounter]->GetName().Equals("Beck"))
				{

					//check to see if the attack occurred. 
					if (bAttackOccurred == true)
					{
						TurnCounter++;
						if (TurnCounter == TurnOrder.Num())
						{
							RoundCounter++;
						}
						TurnCounter %= TurnOrder.Num();
						CombatPhase = ECombatPhase::Decision;
						bAttackOccurred = false; 
						break; 
					}
					else
					{
						
						break; 
					}
				}
			}
			else 
			{
				bAttackOccurred = false; 
				TurnOrder[TurnCounter]->Attack();
				TurnCounter++;
				if (TurnCounter == TurnOrder.Num())
				{
					RoundCounter++;
				}
				TurnCounter %= TurnOrder.Num(); 
				CombatPhase = ECombatPhase::Decision;
				break;
			}
			

		case ECombatPhase::Defeat:
			break;

		case ECombatPhase::Victory:
			break;
	}

	
}

