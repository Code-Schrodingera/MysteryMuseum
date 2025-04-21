#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Norms/SNorms/ISNorm.h"
#include "Norms/TNorms/ITNorm.h"
#include "Rule/FRule.h"
#include "Variable/FVariable.h"
#include "Aggregation/IAggregation.h"
#include "Activation/IActivation.h"
#include "Accumulation/IAccumulation.h"
#include "Defuzzification/IDefuzzification.h"
#include "FEngine.generated.h"


UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UFEngine : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<UTNorm>  AndTNorm;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<USNorm>  OrSNorm;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<UAggregation> Aggregation;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<UActivation> Activation;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<UAccumulation> Accumulation;

	UPROPERTY(EditAnywhere, Category = "Fuzzy|Engine")
	TScriptInterface<UDefuzzification> Defuzzification;

public:
	UFEngine();

	UFUNCTION(BlueprintCallable, Category = "Fuzzy")
		float Evaluate(TArray<UFVariable*> Variables, TArray<UFRule*> Rules);
};