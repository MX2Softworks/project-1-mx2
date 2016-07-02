// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GameCharacter.generated.h"

//delegate that will broadcast event for each character's attack.
//TODO: Move to enemy class and implement there.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOrbAttack);

UCLASS()
class PROJECTONE_API AGameCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGameCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	int GetSpeed();

	void SetSpeed(int NewSpeed);

	void DelayTest();

	//Possible debug function for getting entities in game to attack in the prototype
	UFUNCTION(BlueprintCallable, Category="Attack")
	virtual bool Attack();

	//On defense event for each enemy
	UPROPERTY(BlueprintAssignable)
	FOnOrbAttack OnOrbAttack;

private:

	UPROPERTY(EditAnywhere)
	int Speed;
};
