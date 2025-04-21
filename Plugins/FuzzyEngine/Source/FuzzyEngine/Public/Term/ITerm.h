#pragma once

#include "UObject/Interface.h"
#include "ITerm.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UTerm : public UInterface { GENERATED_BODY() };

class ITerm
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Fuzzy|Term")
        float Evaluate(float X) const;   // µ(x)
};