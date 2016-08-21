// no stealing

#pragma once

#include "Components/ActorComponent.h"
#include "Weapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTONE_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

public:	
	///===============================================================================================
	/// Constructors
	///===============================================================================================

	// Sets default values for this component's properties
	UWeapon();


	///===============================================================================================
	/// Inheritied
	///===============================================================================================
		
		// Called when the game starts
		virtual void BeginPlay() override;
	
		// Called every frame
		virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	///===============================================================================================
	/// Getters and Setters
	///===============================================================================================
		
		//Used to get and/or set the DamagePerHit variable which is used to deal a damage value as a base. 
		UFUNCTION(BlueprintCallable, Category = "Weapon Damage")
		float GetDamagePerHit();
		UFUNCTION(BlueprintCallable, Category = "Weapon Damage")
		void SetDamagePerHit(float NewDamagePerHit);

		//Used to get and/or set the Name of the weapon in-game. 
		UFUNCTION(BlueprintCallable, Category = "Weapon Name")
		FString GetWeaponName();
		UFUNCTION(BlueprintCallable, Category = "Weapon Name")
		void SetWeaponName(FString NewWeapoName); 
		
private:

	//Specifies the point value of damage on a successful hit to an enemy. 
	UPROPERTY(EditAnywhere)
	float DamagePerHit = 0.f;

	//The in-game name of the weapon 
	UPROPERTY(EditAnywhere)
	FString WeaponName = "weapon";
		

	
};
