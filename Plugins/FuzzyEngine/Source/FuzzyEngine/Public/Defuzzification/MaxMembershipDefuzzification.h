#pragma once

#include "Defuzzification/IDefuzzification.h"
#include "MaxMembershipDefuzzification.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UMaxMembershipDefuzzification : public UObject, public IDefuzzification
{
    GENERATED_BODY()
public:
    virtual float Defuzzify_Implementation(const TArray<float>& X, const TArray<float>& Mu) const override;
};