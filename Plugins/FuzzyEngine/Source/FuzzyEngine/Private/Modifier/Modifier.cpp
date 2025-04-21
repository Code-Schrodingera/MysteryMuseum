#include "Modifier/Modifier.h"
#include "Modifier/ModifierNot.h"
#include "Modifier/ModifierVery.h"
#include "Modifier/ModifierApprox.h"

UModifier* UModifier::CreateFromToken(const FString& Token)
{
    if (Token.Equals(TEXT("NOT"), ESearchCase::IgnoreCase)) { return NewObject<UNegateModifier>(); }
    if (Token.Equals(TEXT("VERY"), ESearchCase::IgnoreCase)) { return NewObject<UVeryModifier>(); }
    if (Token.Equals(TEXT("APPROX"), ESearchCase::IgnoreCase)) { return NewObject<UApproxModifier>(); }
    return nullptr;
}