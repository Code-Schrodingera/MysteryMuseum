#pragma once
#include "UObject/Interface.h"
#include "ITNorm.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UTNorm : public UInterface { GENERATED_BODY() };

/**  Generalised AND‑operator (T‑norm) */
class FUZZYENGINE_API ITNorm
{
    GENERATED_BODY()
public:
    /**  Apply(a,b) ∈ [0;1] */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|TNorm")
        float Apply(float A, float B) const;
};