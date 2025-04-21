#include "Rule/FRule.h"
#include "Variable/FVariable.h"
#include "Term/ITerm.h"
#include "Norms/TNorms/MinTNorm.h"
#include "Norms/SNorms/MaxSNorm.h"

float UFRule::EvaluateAntecedent() const
{
    // 1) найдём активные нормы: приоритет – собственные, затем дефолт из движка, затем Min/Max
    const ITNorm* TNorm = TNormOp ? Cast<ITNorm>(TNormOp.GetObject())
        : GetDefault<UMinTNorm>();
    const ISNorm* SNorm = SNormOp ? Cast<ISNorm>(SNormOp.GetObject())
        : GetDefault<UMaxSNorm>();

    float Acc = 1.f;
    bool bPrevIsOr = false;
    for (const FClause& Clause : Clauses)
    {
        const float Mu = Clause.Evaluate();
        Acc = bPrevIsOr ? SNorm->Execute_Apply(SNorm->GetUObject(), Acc, Mu)
            : TNorm->Execute_Apply(TNorm->GetUObject(), Acc, Mu);
        bPrevIsOr = Clause.bIsOrWithNext;
    }
    return Acc;
}

void UFRule::UpdateSamples() const
{
    if (!ConsequentTerm) { CachedSamples.Empty(); return; }

    CachedSamples.Empty(100);

    const float MinX = ITerm::Execute_GetUniverseMin(ConsequentTerm.GetObject());
    const float MaxX = ITerm::Execute_GetUniverseMax(ConsequentTerm.GetObject());
    const float Step = (MaxX - MinX) / 99.f;

    for (int32 i = 0; i < 100; ++i)
    {
        const float X = MinX + i * Step;
        const float Mu = ITerm::Execute_Evaluate(ConsequentTerm.GetObject(), X);
        CachedSamples.Emplace(X, Mu);
    }
    bSamplesDirty = false;
}