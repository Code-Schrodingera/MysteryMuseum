#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Norms/TNorms/ITNorm.h"
#include "Norms/SNorms/ISNorm.h"
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
	UPROPERTY(EditAnywhere, Category = "Fuzzy|Rule")
	TScriptInterface<ITNorm> TNormOp;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Rule")
	TScriptInterface<ISNorm> SNormOp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FClause> Clauses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<UTerm> ConsequentTerm;

public:
	float EvaluateAntecedent() const;
	const TArray<TPair<float, float>>& GetConsequentSamples() const;

private:
	mutable TArray<TPair<float, float>> CachedSamples;
	mutable bool bSamplesDirty = true;

	void UpdateSamples() const;
};