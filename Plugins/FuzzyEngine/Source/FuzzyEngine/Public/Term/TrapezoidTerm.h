#pragma once

#include "Term/ITerm.h"
#include "TrapezoidTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UTrapezoidTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float A = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float B = 0.25f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float C = 0.75f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float D = 1.f;

    virtual float Evaluate_Implementation(float X) const override
    {
        if (X <= A || X >= D) return 0.f;
        if (X >= B && X <= C) return 1.f;
        if (X < B) return (X - A) / (B - A);
        return (D - X) / (D - C);
    }
};