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

	// ...
	
}


// Called every frame
void UPaneManager::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	
}

// For use in Blueprints ONLY to get the engaged enemy.
void UPaneManager::RetrieveEngagedEnemy(AEnemy* EngagedEnemy) {
	BaseEnemy = EngagedEnemy;
}

