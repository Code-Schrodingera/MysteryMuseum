#pragma once

#include "UObject/Interface.h"
#include "IAccumulation.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UAccumulation : public UInterface { GENERATED_BODY() };

class IAccumulation
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Fuzzy|Accumulation")
        float Accumulate(float Prev, float New) const;
};