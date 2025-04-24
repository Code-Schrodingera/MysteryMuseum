#include "Engine/FEngine.h"
#include "Variable/FVariable.h"
#include "Rule/FRule.h"
#include "Norms/TNorms/MinTNorm.h"
#include "Norms/SNorms/MaxSNorm.h"
#include "Aggregation/MinAggregation.h"
#include "Activation/ProdActivation.h"
#include "Accumulation/MaxAccumulation.h"
#include "Variable/TermSelector.h"
#include "Defuzzification/WheelAuctionDefuzzification.h"

UFEngine::UFEngine()
{
    AndTNorm = CreateDefaultSubobject<UMinTNorm>(TEXT("AndTNorm"));
    OrSNorm = CreateDefaultSubobject<UMaxSNorm>(TEXT("OrSNorm"));
    Aggregation = CreateDefaultSubobject<UMinAggregation>(TEXT("MinAgg"));
    Activation = CreateDefaultSubobject<UProdActivation>(TEXT("ProdAct"));
    Accumulation = CreateDefaultSubobject<UMaxAccumulation>(TEXT("MaxAcc"));
    Defuzzification = CreateDefaultSubobject<UWheelAuctionDefuzzification>(TEXT("WheelDefuzz"));
    TermSelector = CreateDefaultSubobject<UTermSelector>(TEXT("TermSelector"));
}

float UFEngine::Evaluate(TArray<UFRule*> Rules)
{
    TMap<float, float> OutputSamples;

    for (UFRule* Rule : Rules)
    {
        if (!Rule) { continue; }
        float Strength = Rule->EvaluateAntecedent();

        for (const TPair<float, float>& Pair : Rule->GetConsequentSamples())
        {
            const float ActivatedMu = IActivation::Execute_Apply(Activation.GetObject(),
                Strength, Pair.Value);

            const float Prev = OutputSamples.FindRef(Pair.Key);
            const float New = IAccumulation::Execute_Accumulate(Accumulation.GetObject(),
                Prev, ActivatedMu);
            OutputSamples.Add(Pair.Key, New);
        }

    }

    // Convert map → parallel arrays for defuzzification
    TArray<float> X, Mu;
    OutputSamples.GetKeys(X);
    X.Sort();
    for (float Key : X) { Mu.Add(OutputSamples[Key]); }

    return IDefuzzification::Execute_Defuzzify(Defuzzification.GetObject(), X, Mu);
}