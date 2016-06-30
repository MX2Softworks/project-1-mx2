// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GameCharacter.generated.h"

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
	bool Attack();

private:

	UPROPERTY(EditAnywhere)
	int Speed;
};
