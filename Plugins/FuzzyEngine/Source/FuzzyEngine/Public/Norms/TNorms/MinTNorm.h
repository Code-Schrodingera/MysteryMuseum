#pragma once
#include "Norms/TNorms/ITNorm.h"
#include "MinTNorm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UMinTNorm : public UObject, public ITNorm
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float A, float B) const override { return FMath::Min(A, B); }
};