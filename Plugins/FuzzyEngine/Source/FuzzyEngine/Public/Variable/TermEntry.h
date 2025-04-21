#pragma once

#include "CoreMinimal.h"
#include "TermEntry.generated.h"

class UTerm;

/** Элемент массива Terms внутри UFVariable (имя + сам терм) */
USTRUCT(BlueprintType)
struct FUZZYENGINE_API FTermEntry
{
    GENERATED_BODY()

    /** Имя терма (Slow, Fast) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    /** Экземпляр терма */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TScriptInterface<UTerm> Term;
};