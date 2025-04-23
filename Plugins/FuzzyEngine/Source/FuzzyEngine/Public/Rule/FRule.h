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
UCLASS(Blueprintable, EditInlineNew, BlueprintType)
class FUZZYENGINE_API UFRule : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Fuzzy|Rule")
	TScriptInterface<UTNorm> TNormOp;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Rule")
	TScriptInterface<USNorm> SNormOp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FClause> Clauses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTerm* ConsequentTerm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StepsForRule = 1000;

public:
	float EvaluateAntecedent() const;
	const TArray<TPair<float, float>>& GetConsequentSamples() const;

private:
	mutable TArray<TPair<float, float>> CachedSamples;
	mutable bool bSamplesDirty = true;

	void UpdateSamples() const;
};