// no stealing

#include "ProjectOne.h"
#include "PaneManager.h"


// Sets default values for this component's properties
UPaneManager::UPaneManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	EnemiesInBattle.Init(nullptr, 50);
	Panes.Init(nullptr, 18);
}


// Called when the game starts
void UPaneManager::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UPaneManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Populates the EnemiesInBattle before arranging them on the Panes
	if (this->GetGotBaseEnemy() == true) 
	{
		
		switch (HashIt(this->GetBaseEnemy()->GetTypeIdentifier())) {
		case EEnemyType::eSluagh:
			{
			int32 EnemiesToAdd = FMath::RandRange(0, 4);
			for (int32 i = 0; i < EnemiesToAdd; i++) {

				// Percentages with if statements

			}
			}
			break;
		default:
			break;
		}
		// CODE TO ADD ENEMIES BASED ON THE BASEENEMY

		this->SetGotBaseEnemy(false);
	}
	
}

// For use in Blueprints ONLY to get the engaged enemy.
void UPaneManager::RetrieveEngagedEnemy(AEnemy* EngagedEnemy) {
	BaseEnemy = EngagedEnemy;
	this->SetGotBaseEnemy(true);
	this->GetEnemiesInBattle().Add(BaseEnemy);
}

EEnemyType UPaneManager::HashIt(FString bTypeIdentifier) {
	if (bTypeIdentifier == "Sluagh") return EEnemyType::eSluagh;
	return EEnemyType::eNotSluagh;
}

// Getter for GotBaseEnemy
bool UPaneManager::GetGotBaseEnemy() { return GotBaseEnemy; }
// Setter for GotBaseEnemy
void UPaneManager::SetGotBaseEnemy(bool bGotBaseEnemy) { GotBaseEnemy = bGotBaseEnemy; }

// Getter for EnemiesInBattle
TArray<AEnemy*> UPaneManager::GetEnemiesInBattle() { return EnemiesInBattle; }

// Getter for Panes
TArray<AEnemy*> UPaneManager::GetPanes() { return Panes; }

// Getter for BaseEnemy
AEnemy* UPaneManager::GetBaseEnemy() { return BaseEnemy; }
// Setter for BaseEnemy
void UPaneManager::SetBaseEnemy(AEnemy* bBaseEnemy) { BaseEnemy = bBaseEnemy; }