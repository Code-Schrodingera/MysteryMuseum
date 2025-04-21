#pragma once

#include "Term/ITerm.h"
#include "TriangularTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UTriangularTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float A = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float B = 0.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float C = 1.f;

    virtual float Evaluate_Implementation(float X) const override
    {
        if (X <= A || X >= C) return 0.f;
        if (FMath::IsNearlyEqual(X, B)) return 1.f;
        return (X < B) ? (X - A) / (B - A) : (C - X) / (C - B);
    }
};