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


UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	eSluagh UMETA(DisplayName = "Sluagh"),
	eNotSluagh UMETA(DisplayName = "NotSluagh")
};

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

	// Return the enum equilvalent of the type identifier to be used in the switch.
	EEnemyType HashIt(FString bTypeIdentifier);


	/// GETTERS

	// Getter for GotBaseEnemy
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	bool GetGotBaseEnemy();

	// Getter for EnemiesInBattle
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	TArray<AEnemy*> GetEnemiesInBattle();

	// Getter for Panes
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	TArray<AEnemy*> GetPanes();

	// Getter for BaseEnemy
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	AEnemy* GetBaseEnemy();


	/// SETTERS

	// Setter for GotBaseEnemy
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	void SetGotBaseEnemy(bool bGotBaseEnemy);

	// Setter for BaseEnemy
	UFUNCTION(BlueprintCallable, Category = "Pane Manager")
	void SetBaseEnemy(AEnemy* bBaseEnemy);


private:

	// A list of the enemies in battle in the order they entered
	TArray<AEnemy*> EnemiesInBattle;

	// A representation of the panes on screen
	TArray<AEnemy*> Panes;

	// The enemy that was engaged upon in the overworld
	AEnemy* BaseEnemy;

	// Defaults to false but is true when RetrieveEngagedEnemy is called
	bool GotBaseEnemy = false;
	
};
