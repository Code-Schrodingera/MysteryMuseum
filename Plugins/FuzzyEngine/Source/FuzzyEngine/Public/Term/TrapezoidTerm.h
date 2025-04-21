#pragma once
#include "Term/ITerm.h"
#include "TrapezoidTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UTrapezoidTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float A = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float B = 0.3f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float C = 0.7f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float D = 1.f;

    virtual float Evaluate_Implementation(float X) const override
    {
        if (X <= A || X >= D) return 0.f;
        if (X >= B && X <= C) return 1.f;
        return (X < B) ? (X - A) / (B - A) : (D - X) / (D - C);
    }
    virtual float GetUniverseMin_Implementation() const override { return A; }
    virtual float GetUniverseMax_Implementation() const override { return D; }
};