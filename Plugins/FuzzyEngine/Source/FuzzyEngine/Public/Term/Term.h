#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Term.generated.h"


UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = "Fuzzy|Term")
class FUZZYENGINE_API UTerm : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float Evaluate(float x) const;
    virtual float Evaluate_Implementation(float x) const PURE_VIRTUAL(UTerm::Evaluate_Implementation, return 0.f;);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float GetUniverseMin() const;
    virtual float GetUniverseMin_Implementation() const PURE_VIRTUAL(UTerm::GetUniverseMin_Implementation, return 0.f;);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float GetUniverseMax() const;
    virtual float GetUniverseMax_Implementation() const PURE_VIRTUAL(UTerm::GetUniverseMax_Implementation, return 1.f;);
};