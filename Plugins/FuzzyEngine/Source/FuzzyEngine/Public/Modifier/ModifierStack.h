#pragma once

#include "Modifier/Modifier.h"
#include "ModifierStack.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UModifierStack : public UModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
    TArray<UModifier*> Modifiers;

    virtual float Apply(float Mu) const override
    {
        for (const UModifierBase* Mod : Modifiers)
        {
            Mu = Mod ? Mod->Apply(Mu) : Mu;
        }
        return Mu;
    }

    float ApplyStack(float Mu) const { return Apply(Mu); }
};