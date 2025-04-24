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

class UTermSelector;

UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UFEngine : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UTermSelector> TermSelector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UTNorm>  AndTNorm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<USNorm>  OrSNorm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UAggregation> Aggregation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UActivation> Activation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UAccumulation> Accumulation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Engine")
	TScriptInterface<UDefuzzification> Defuzzification;

public:
	UFEngine();

	UFUNCTION(BlueprintCallable, Category = "Fuzzy")
	float Evaluate(TArray<UFRule*> Rules);
};