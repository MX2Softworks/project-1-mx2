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
			EntitiesComingIn[0] = GetWorld()->GetFirstPlayerController();
			UE_LOG(LogTemp, Warning, TEXT("got player controller successfully"));
		}
		else 
		{
			UE_LOG(LogTemp, Error, TEXT("World exists. But no player controller."));
		}
		
	}

	//TODO: Get reference for sluagh to add to EntitiesComingIn
	// ...
}

//TODO: Implement Engagement System
//Constructor that will take an array of actors in combat to create the turn order. 
UBattleManager::UBattleManager(TArray<AActor*> EntitiesInCombat) 
{

	// ...

}

//TODO: Make this work with the Engagement System
TArray<AActor*> UBattleManager::InitializeTurnOrder()
{
	//Initialize TArray of size 10 to nullptr
	//For each entity reference:
		//get the speed
		//for each index of the turn order array:
			//if index % speed is 0 insert reference into index
		
	//return initialized TurnOrderList

	TurnOrder.Init(nullptr, 10);


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

