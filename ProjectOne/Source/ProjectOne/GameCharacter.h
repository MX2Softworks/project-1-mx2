// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include <string>
#include "GameCharacter.generated.h"

//delegate that will broadcast event for each character's attack.
//TODO: Move to enemy class and implement there.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttack);

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

	// Speed is used for turn order in battle 
	UFUNCTION(BlueprintCallable, Category = "Speed")
	int32 GetSpeed();
	UFUNCTION(BlueprintCallable, Category = "Speed")
	void SetSpeed(int32 NewSpeed);

	// IsAttacking is used as a flag for when Orb Patterns or attacks are active
	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool GetIsAttacking(); 
	UFUNCTION(BlueprintCallable, Category = "Attack")
	void SetIsAttacking(bool isAttacking);

	// Getter and Setter for TypeIdentifier
	UFUNCTION(BlueprintCallable, Category = "GameCharacter")
	FString GetTypeIdentifier();
	UFUNCTION(BlueprintCallable, Category = "GameCharacter")
	void SetTypeIdentifier(FString bTypeIdentifier);

	// Inheritable function that contains the attack of a character
	UFUNCTION(BlueprintCallable, Category="Attack")
	virtual bool Attack();

	// Multicast Delegate used to trigger the character's first attack
	UPROPERTY(BlueprintAssignable)
	FOnAttack OnAttack_1;

private:

	// Speed is used for turn order in battle, the lower the number the more frequent a character goes
	UPROPERTY(EditAnywhere)
	int32 Speed;

	// IsAttacking is used as a flag to tell the manager and other classes that an attack is active
	UPROPERTY(EditAnywhere)
	bool bIsAttacking = false;

	// String to label what type each character is
	FString TypeIdentifier;
};
