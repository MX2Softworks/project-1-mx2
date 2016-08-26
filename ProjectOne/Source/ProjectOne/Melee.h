// no stealing

#pragma once

#include "Weapon.h"
#include "Melee.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTONE_API UMelee : public UWeapon
{
	GENERATED_BODY()
	
public:

	//Gets and/or Sets the swing length which is used to determine how long the melee drawer's line can be.
	UFUNCTION(BlueprintCallable, Category = "Swing Length")
	float GetSwingLength();
	UFUNCTION(BlueprintCallable, Category = "Swing Length")
	void  SetSwingLength(float NewSwingLength);

	//Gets and/or Sets the maximum number of swings that are allowed before the end of the turn.
	UFUNCTION(BlueprintCallable, Category = "Number of Swings")
	int32 GetMaxSwings();
	UFUNCTION(BlueprintCallable, Category = "Number of Swings")
	void  SetMaxSwings(int32 NewMaxSwings);

	//Gets and/or Sets whether the attack with the weapon has ended and the turn is over for the user. 
	UFUNCTION(BlueprintCallable, Category = "Is Attack Over?")
	bool GetAttackOver();
	UFUNCTION(BlueprintCallable, Category = "Is Attack Over?")
	void SetAttackOver(bool NewAttackOver);


private:

	// Used to determine the max length of the line the melee drawer allows.
	UPROPERTY(EditAnywhere)
	float SwingLength = 30.f; 

	// Determines the number of swings the user can make before the turn ends. 
	UPROPERTY(EditAnywhere)
	int32 MaxSwings = 1; 
	
	// Is set to true when the attack is over to let the manager know it can end the user's turn. 
	UPROPERTY(EditAnywhere)
	bool AttackOver = false; 


	
};
