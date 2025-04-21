#pragma once

#include "UObject/Object.h"
#include "Modifier.generated.h"

/** Базовый класс модификаторов */
UCLASS(Abstract, BlueprintType, EditInlineNew)
class FUZZYENGINE_API UModifier : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Fuzzy|Modifier")
    virtual float Apply(float Mu) const { return Mu; }

    static UModifier* CreateFromToken(const FString& Token);
};