#pragma once
#include "UObject/Interface.h"
#include "ISNorm.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class USNorm : public UInterface { GENERATED_BODY() };

/**  Generalised OR‑operator (S‑norm) */
class FUZZYENGINE_API ISNorm
{
    GENERATED_BODY()
public:
    /**  Apply(a,b) ∈ [0;1] */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|SNorm")
        float Apply(float A, float B) const;
};