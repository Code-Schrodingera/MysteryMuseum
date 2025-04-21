#pragma once

#include "UObject/Interface.h"
#include "IActivation.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UActivation : public UInterface { GENERATED_BODY() };

/** Соединяет силу правила с выходной MF */
class IActivation
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Fuzzy|Activation")
    float Apply(float RuleStrength, float Membership) const;
};