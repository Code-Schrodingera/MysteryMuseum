#pragma once
#include "Norms/TNorms/ITNorm.h"
#include "ProbTNorm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UProbTNorm : public UObject, public ITNorm
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float A, float B) const override { return A * B; }
};