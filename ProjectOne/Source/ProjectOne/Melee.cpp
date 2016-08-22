// no stealing

#include "ProjectOne.h"
#include "Melee.h"

// Getter and Setter for SwingLength.
float UMelee::GetSwingLength(){ return SwingLength; }
void  UMelee::SetSwingLength(float NewSwingLength){ SwingLength = NewSwingLength; }

// Getter and Setter for MaxSwings. 
int32 UMelee::GetMaxSwings(){ return MaxSwings; }
void  UMelee::SetMaxSwings(int32 NewMaxSwings){ MaxSwings = NewMaxSwings; }

// Getter and Setter for AttackOver. 
bool UMelee::GetAttackOver(){ return AttackOver; }
void UMelee::SetAttackOver(bool NewAttackOver){ AttackOver = NewAttackOver; }


