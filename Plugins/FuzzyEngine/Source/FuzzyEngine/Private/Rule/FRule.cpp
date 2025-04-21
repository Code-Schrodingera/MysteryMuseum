#include "Rule/FRule.h"
#include "Variable/FVariable.h"
#include "Term/Term.h"
#include "Norms/TNorms/MinTNorm.h"
#include "Norms/SNorms/MaxSNorm.h"

float UFRule::EvaluateAntecedent() const
{
    const UObject* TNormObj = TNormOp ? TNormOp.GetObject() : GetDefault<UMinTNorm>();
    const UObject* SNormObj = SNormOp ? SNormOp.GetObject() : GetDefault<UMaxSNorm>();

    float Acc = 1.f;
    bool  bPrevIsOr = false;

    for (const FClause& Clause : Clauses)
    {
        const float Mu = Clause.Evaluate();

        Acc = bPrevIsOr
            ? ISNorm::Execute_Apply(SNormObj, Acc, Mu)
            : ITNorm::Execute_Apply(TNormObj, Acc, Mu);

        bPrevIsOr = (Clause.OpWithNext == EOp::OR);
    }
    return Acc;
}

const TArray<TPair<float, float>>& UFRule::GetConsequentSamples() const
{
    if (bSamplesDirty) { UpdateSamples(); }
    return CachedSamples;
}

void UFRule::UpdateSamples() const
{
    if (!ConsequentTerm) { CachedSamples.Empty(); return; }

    CachedSamples.Empty(100);

    const float MinX = ConsequentTerm->GetUniverseMin();
    const float MaxX = ConsequentTerm->GetUniverseMax();
    const float Step = (MaxX - MinX) / 99.f;

    for (int32 i = 0; i < 100; ++i)
    {
        const float X = MinX + i * Step;
        const float Mu = ConsequentTerm->Evaluate(X);
        CachedSamples.Emplace(X, Mu);
    }
    bSamplesDirty = false;
}