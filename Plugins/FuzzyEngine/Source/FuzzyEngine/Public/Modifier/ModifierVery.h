#pragma once

#include "Modifier/Modifier.h"
#include "ModifierVery.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UModifierVery : public UModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Power = 2.f; // µ^Power
    virtual float Apply(float Mu) const override { return FMath::Pow(Mu, Power); }
};