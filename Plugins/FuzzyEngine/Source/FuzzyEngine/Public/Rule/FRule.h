#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Aggregation/IAggregation.h"
#include "Activation/IActivation.h"
#include "Rule/FClause.h"        // см. ниже
#include "FRule.generated.h"

class UFVariable;
class UTerm;

/** Полное правило MISO: Antecedent -> ConsequentTerm */
UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UFRule : public UObject
{
	GENERATED_BODY()

public:
	/** Литералы «Var IS [Mod…] Term» + связки AND/OR */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FClause> Clauses;

	/** Терм вывода */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<UTerm> ConsequentTerm;

public:
	/** min‑T‑norm для AND, max‑S‑norm для OR */
	float EvaluateAntecedent() const;

	/** Дискретизация ConsequentTerm (100 точек) */
	const TArray<TPair<float, float>>& GetConsequentSamples() const;

private:
	mutable TArray<TPair<float, float>> CachedSamples;
	mutable bool bSamplesDirty = true;

	void UpdateSamples() const;
};