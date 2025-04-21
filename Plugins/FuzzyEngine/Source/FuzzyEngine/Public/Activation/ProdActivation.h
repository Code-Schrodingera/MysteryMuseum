#pragma once

#include "Activation/IActivation.h"
#include "ProdActivation.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UProdActivation : public UObject, public IActivation
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float RuleStrength, float Membership) const override
    {
        return RuleStrength * Membership;
    }
};