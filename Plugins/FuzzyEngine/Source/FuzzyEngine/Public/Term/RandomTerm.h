#pragma once

#include "Term/ITerm.h"
#include "RandomTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API URandomTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float A = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float B = 1.f;

    virtual float Evaluate_Implementation(float /*X*/) const override
    {
        return FMath::FRand();
    }

    virtual float GetUniverseMin_Implementation() const override { return A; }
    virtual float GetUniverseMax_Implementation() const override { return B; }
};