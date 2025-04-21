#include "Rule/FRule.h"
#include "Variable/FVariable.h"
#include "Term/UTerm.h"
#include "Aggregation/MinAggregator.h"
#include "Accumulation/MaxAccumulation.h"

float UFR​ule::EvaluateAntecedent() const
{
	const UMinAggregator* MinAgg = GetDefault<UMinAggregator>();
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

void UFR​ule::UpdateSamples() const
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
		const float Mu = ConsequentTerm->Evaluate(X);
		CachedSamples.Add({ X, Mu });
	}
	bSamplesDirty = false;
}

const TArray<TPair<float, float>>& UFR​ule::GetConsequentSamples() const
{
	if (bSamplesDirty)
	{
		UpdateSamples();
	}
	return CachedSamples;
}