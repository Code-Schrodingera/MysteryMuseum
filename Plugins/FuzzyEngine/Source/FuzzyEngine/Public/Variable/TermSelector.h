#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "TermSelector.generated.h"

class UFVariable;
class UTerm;


UCLASS(Blueprintable, EditInlineNew, BlueprintType)
class FUZZYENGINE_API UTermSelector : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Engine")
    FString SelectTerm(UFVariable* Var, float Crisp) const;
};