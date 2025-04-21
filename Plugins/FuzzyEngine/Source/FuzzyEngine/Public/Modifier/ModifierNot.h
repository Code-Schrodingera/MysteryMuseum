#pragma once

#include "Modifier/Modifier.h"
#include "ModifierNot.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UModifierNot : public UModifier
{
    GENERATED_BODY()
public:
    virtual float Apply(float Mu) const override { return 1.f - Mu; }
};