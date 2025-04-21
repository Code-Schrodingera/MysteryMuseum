#pragma once

#include "Term/ITerm.h"
#include "Math/UnrealMathUtility.h"
#include "GaussianTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UGaussianTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Mean = 0.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Sigma = 0.2f;

    virtual float Evaluate_Implementation(float X) const override
    {
        return FMath::Exp(-FMath::Square((X - Mean) / Sigma) / 2.f);
    }

    virtual float GetUniverseMin_Implementation() const override { return Mean - 3 * Sigma; }
    virtual float GetUniverseMax_Implementation() const override { return Mean + 3 * Sigma; }
};