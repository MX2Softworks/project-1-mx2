// no stealing

#include "ProjectOne.h"
#include "Weapon.h"

// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// Getters and Setters for DamagePerHit
float UWeapon::GetDamagePerHit() { return DamagePerHit; }
void UWeapon::SetDamagePerHit(float NewDamagePerHit) { DamagePerHit = NewDamagePerHit; }

// Getters and Setters for WeaponName
FString UWeapon::GetWeaponName(){ return WeaponName; }
void UWeapon::SetWeaponName(FString NewWeaponName) { WeaponName = NewWeaponName; }

// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();
	// ...
}

// Called every frame
void UWeapon::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


