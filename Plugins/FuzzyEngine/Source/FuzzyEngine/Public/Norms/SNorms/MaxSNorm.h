#pragma once

#include "Norms/SNorms/ISNorm.h"
#include "MaxSNorm.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UMaxSNorm : public UObject, public ISNorm
{
    GENERATED_BODY()
public:
    virtual float Apply_Implementation(float A, float B) const override { return FMath::Max(A, B); }
};