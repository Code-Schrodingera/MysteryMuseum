#pragma once
#include "UObject/Interface.h"
#include "IDefuzzification.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UDefuzzification : public UInterface { GENERATED_BODY() };

class IDefuzzification
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Fuzzy|Defuzz")
        float Defuzzify(const TArray<float>& X, const TArray<float>& Mu) const; // Assumes same length
};