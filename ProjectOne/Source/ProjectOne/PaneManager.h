// no stealing

#pragma once

#include "Components/ActorComponent.h"
#include "GameCharacter.h"
#include "MainCharacter.h"
#include "Mob.h"
#include "Enemy.h"
#include "Sluagh.h"
#include "EngineUtils.h"
#include "PaneManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTONE_API UPaneManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPaneManager();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// Saves the enemy that was engaged upon
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	void RetrieveEngagedEnemy(AEnemy* EngagedEnemy);

private:

	// A list of the enemies in battle in the order they entered
	TArray<AEnemy*> EnemiesInBattle;

	// A representation of the panes on screen
	TArray<AEnemy*> Panes;

	// The enemy that was engaged upon in the overworld
	AEnemy* BaseEnemy;
	
};
