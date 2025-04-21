#pragma once

#include "Term/ITerm.h"
#include "CrispTerm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UCrispTerm : public UObject, public ITerm
{
    GENERATED_BODY()
public:
    /** Порог >= */
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Threshold = 0.f;

    virtual float Evaluate_Implementation(float X) const override
    {
        return X >= Threshold ? 1.f : 0.f;
    }
};