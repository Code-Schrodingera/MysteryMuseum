#include "Engine/FEngine.h"
#include "Variable/FVariable.h"
#include "Rule/FRule.h"
#include "Norms/TNorms/MinTNorm.h"
#include "Norms/SNorms/MaxSNorm.h"
#include "Aggregation/MinAggregation.h"
#include "Activation/ProdActivation.h"
#include "Accumulation/MaxAccumulation.h"
#include "Defuzzification/WheelAuctionDefuzzification.h"

UFEngine::UFEngine()
{
    AndTNorm = CreateDefaultSubobject<UMinTNorm>(TEXT("AndTNorm"));
    OrSNorm = CreateDefaultSubobject<UMaxSNorm>(TEXT("OrSNorm"));
    Aggregation = CreateDefaultSubobject<UMinAggregation>(TEXT("MinAgg"));
    Activation = CreateDefaultSubobject<UProdActivation>(TEXT("ProdAct"));
    Accumulation = CreateDefaultSubobject<UMaxAccumulation>(TEXT("MaxAcc"));
    Defuzzification = CreateDefaultSubobject<UWheelAuctionDefuzzification>(TEXT("WheelDefuzz"));
}

float UFEngine::Evaluate(TArray<UFVariable*> Variables, TArray<UFRule*> Rules)
{
    TMap<float, float> OutputSamples;

    for (UFRule* Rule : Rules)
    {
        if (!Rule) { continue; }
        float Strength = Rule->EvaluateAntecedent();

        // Activate and accumulate samples of this rule
        for (const auto& Pair : Rule->GetConsequentSamples())
        {
            float ActivatedMu = IActivation::Execute_Apply(Activation.GetObject(), Strength, Pair.Value);
            float Prev = OutputSamples.FindRef(Pair.Key);
            float New = IAccumulation::Execute_Accumulate(Accumulation.GetObject(), Prev, ActivatedMu);
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