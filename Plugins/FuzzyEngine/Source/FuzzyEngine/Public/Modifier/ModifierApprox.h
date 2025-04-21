#pragma once

#include "Modifier/Modifier.h"
#include "ModifierApprox.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UModifierApprox : public UModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Exponent = 0.5f; // sqrt by default
    virtual float Apply(float Mu) const override { return FMath::Pow(Mu, Exponent); }
};