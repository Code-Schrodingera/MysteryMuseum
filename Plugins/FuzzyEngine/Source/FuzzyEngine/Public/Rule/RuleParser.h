#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuleParser.generated.h"

class UFR​ule;
class UFVariable;


UCLASS()
class FUZZYENGINE_API URuleParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fuzzy|Rule")
	static UFRule* ParseRuleString(
		const FString& RuleText,
		const TMap<FString, UFVariable*>& Variables
	);
};