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


	InitializeTurnOrder(); 
}

//TODO: Implement Engagement System
//Constructor that will take an array of actors in combat to create the turn order. 
UBattleManager::UBattleManager(TArray<AGameCharacter*> EntitiesInCombat) 
{

	// ...

}

//TODO: Make this work with the Engagement System
TArray<AGameCharacter*> UBattleManager::InitializeTurnOrder()
{
	//Initialize TArray of size 10 to nullptr
	//For each entity reference:
		//get the speed
		//for each index of the turn order array:
			//if index % speed is 0 insert reference into index
		
	//return initialized TurnOrderList

	TurnOrder.Init(nullptr, 10);
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
					if (TurnOrder[Index] == nullptr)
					{
						TurnOrder[Index] = Entity;
					}
					else
					{
						TurnOrder.Insert(Entity, Index + 1);
					}
				}
			}
		}
	}

	for (int Index = 0; Index < TurnOrder.Num(); Index++)
	{
		AGameCharacter* PrintCharacter = TurnOrder[Index];
		if (PrintCharacter != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Round: %d\tEntity: %s"), Index, *PrintCharacter->GetName())
		}
	}

	return TurnOrder; 
}

// Called when the game starts
void UBattleManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBattleManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

