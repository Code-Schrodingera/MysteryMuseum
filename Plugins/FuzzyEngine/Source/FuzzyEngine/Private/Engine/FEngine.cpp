#include "Engine/FEngine.h"
#include "Variable/FVariable.h"
#include "Rule/FRule.h"
#include "Aggregation/MinAggregation.h"
#include "Accumulation/MaxAccumulation.h"
#include "Activation/ProdActivation.h"
#include "Defuzzification/WheelAuctionDefuzzification.h"

UFEngine::UFEngine()
{
	// Создаём дефолтные под‑объекты, чтобы их можно было поменять в Details
	AndAggregation = CreateDefaultSubobject<UMinAggregation>(TEXT("AndAgg"));
	OrAggregation = CreateDefaultSubobject<UMaxAccumulation>(TEXT("OrAgg"));
	Activation = CreateDefaultSubobject<UProdActivation>(TEXT("ProdAct"));
	Accumulation = CreateDefaultSubobject<UMaxAccumulation>(TEXT("MaxAcc"));
	Defuzzification = CreateDefaultSubobject<UWheelAuctionDefuzzification>(TEXT("WheelDefuzz"));
}

float UFEngine::Evaluate()
{
    TMap<float, float> OutputSamples;

    for (UFRule* Rule : Rules)
    {
        if (!Rule) { continue; }

        const float Strength = Rule->EvaluateAntecedent();

        // активируем терм правила
        const auto& Samples = Rule->GetConsequentSamples();
        for (const auto& Pair : Samples)
        {
            const float ActivatedMu =
                IActivation::Execute_Apply(Activation.GetObject(), Strength, Pair.Value);

            const float Prev = OutputSamples.FindRef(Pair.Key);
            const float New =
                IAccumulation::Execute_Accumulate(Accumulation.GetObject(), Prev, ActivatedMu);

            OutputSamples.Add(Pair.Key, New);
        }
    }
    return IDefuzzification::Execute_Defuzzify(Defuzzification.GetObject(), OutputSamples);
}