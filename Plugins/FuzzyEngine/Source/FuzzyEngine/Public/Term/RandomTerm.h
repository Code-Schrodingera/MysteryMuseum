#pragma once

#include "Term/ITerm.h"
#include "RandomTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API URandomTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    virtual float Evaluate_Implementation(float /*X*/) const override
    {
        return FMath::FRand();
    }
};