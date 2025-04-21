#pragma once

#include "CoreMinimal.h"
#include "FClause.generated.h"

class UFVariable;
class UTerm;
class UModifier;          // ваши «NOT, VERY, APPROX»

UENUM(BlueprintType)
enum class EOp : uint8
{
	AND,
	OR
};

USTRUCT(BlueprintType)
struct FUZZYENGINE_API FClause
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFVariable* Variable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UModifier*> Modifiers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<UTerm> Term;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EOp OpWithNext = EOp::AND;

	float Evaluate() const;
};
