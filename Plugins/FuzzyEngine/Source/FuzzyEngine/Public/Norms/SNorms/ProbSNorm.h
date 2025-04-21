#pragma once
#include "Norms/SNorms/ISNorm.h"
#include "ProbSNorm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UProbSNorm : public UObject, public ISNorm
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float A, float B) const override { return A + B - A * B; }
};