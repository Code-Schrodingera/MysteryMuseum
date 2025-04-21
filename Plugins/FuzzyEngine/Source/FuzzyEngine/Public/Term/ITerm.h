#pragma once
#include "UObject/Interface.h"
#include "ITerm.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UTerm : public UInterface { GENERATED_BODY() };

/**  Base interface for any membership‑function (μ‑term) */
class FUZZYENGINE_API ITerm
{
    GENERATED_BODY()
public:
    /** μ(x) ∈ [0;1] */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float Evaluate(float X) const;

    /** Universe boundaries */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float GetUniverseMin() const;
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float GetUniverseMax() const;
};