#pragma once

#include "Aggregation/IAggregation.h"
#include "MinAggregation.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UMinAggregation : public UObject, public IAggregation
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float A, float B) const override { return FMath::Min(A, B); }
};