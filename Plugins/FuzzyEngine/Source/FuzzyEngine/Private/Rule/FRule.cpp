#include "Rule/FRule.h"
#include "Variable/FVariable.h"
#include "Term/ITerm.h"
#include "Aggregation/MinAggregation.h"
#include "Accumulation/MaxAccumulation.h"

float UFRule::EvaluateAntecedent() const
{
	const UMinAggregation* MinAgg = GetDefault<UMinAggregation>();
	const UMaxAccumulation* MaxAgg = GetDefault<UMaxAccumulation>();

	float Acc = 1.f;              // нейтральное для AND
	EOp PrevOp = EOp::AND;        // см. FClause ниже

	for (const FClause& Clause : Clauses)
	{
		const float Mu = Clause.Evaluate();

		if (PrevOp == EOp::AND)
		{
			Acc = MinAgg->Apply(Acc, Mu);
		}
		else                              // OR
		{
			Acc = MaxAgg->Accumulate(Acc, Mu);
		}
		PrevOp = Clause.OpWithNext;
	}

	return Acc;
}

void UFRule::UpdateSamples() const
{
	if (!ConsequentTerm)
	{
		CachedSamples.Empty();
		return;
	}

	CachedSamples.Empty(100);
	const float MinX = ConsequentTerm->GetUniverseMin();
	const float MaxX = ConsequentTerm->GetUniverseMax();
	const float Step = (MaxX - MinX) / 99.f;

	for (int32 i = 0; i < 100; ++i)
	{
		const float X = MinX + i * Step;
		const float Mu = ITerm::Execute_Evaluate(X);
		CachedSamples.Add({ X, Mu });
	}
	bSamplesDirty = false;
}

const TArray<TPair<float, float>>& UFRule::GetConsequentSamples() const
{
	if (bSamplesDirty)
	{
		UpdateSamples();
	}
	return CachedSamples;
}