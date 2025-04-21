#include "Modifier/Modifier.h"
#include "Modifier/ModifierNot.h"
#include "Modifier/ModifierVery.h"
#include "Modifier/ModifierApprox.h"

UModifier* UModifier::CreateFromToken(const FString& Token)
{
    if (Token.Equals(TEXT("NOT"), ESearchCase::IgnoreCase)) { return NewObject<UModifierNot>(); }
    if (Token.Equals(TEXT("VERY"), ESearchCase::IgnoreCase)) { return NewObject<UModifierVery>(); }
    if (Token.Equals(TEXT("APPROX"), ESearchCase::IgnoreCase)) { return NewObject<UModifierApprox>(); }
    return nullptr;
}