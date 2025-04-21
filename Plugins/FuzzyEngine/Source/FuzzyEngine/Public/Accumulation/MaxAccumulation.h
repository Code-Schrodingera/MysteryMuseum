#pragma once

#include "Accumulation/IAccumulation.h"
#include "MaxAccumulation.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UMaxAccumulation : public UObject, public IAccumulation
{
    GENERATED_BODY()
public:
    virtual float Accumulate_Implementation(float Prev, float New) const override
    {
        return FMath::Max(Prev, New);
    }
};