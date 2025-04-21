#pragma once

#include "UObject/Interface.h"
#include "IAggregation.generated.h"


UINTERFACE(MinimalAPI, BlueprintType)
class UAggregation : public UInterface { GENERATED_BODY() };


class IAggregation
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Fuzzy|Aggregation")
    float Apply(float A, float B) const;
};