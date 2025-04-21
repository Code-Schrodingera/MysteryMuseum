#pragma once

#include "UObject/Interface.h"
#include "ITerm.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UTerm : public UInterface
{
    GENERATED_BODY()
};

/** Любая функция принадлежности */
class FUZZYENGINE_API ITerm
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuzzy|Term")
        float Evaluate(float X) const;
};