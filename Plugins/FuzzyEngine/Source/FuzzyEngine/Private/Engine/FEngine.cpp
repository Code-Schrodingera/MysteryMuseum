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

	for (const TObjectPtr<UFR​ule>& Rule : Rules)
	{
		if (!Rule) { continue; }

		// сила правила
		const float Strength = Rule->EvaluateAntecedent();

		// активируем выходной терм
		const TArray<TPair<float, float>>& Samples = Rule->GetConsequentSamples();
		for (const TPair<float, float>& Pair : Samples)
		{
			const float ActivatedMu = Activation->Apply(Strength, Pair.Value);
			const float AccValue = OutputSamples.FindRef(Pair.Key);
			OutputSamples.Add(Pair.Key, Accumulation->Accumulate(AccValue, ActivatedMu));
		}
	}

	return Defuzzification->Defuzzify(OutputSamples);
}