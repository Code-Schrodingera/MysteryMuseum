#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuleParser.generated.h"

class UFR​ule;
class UFVariable;

/**
 * Функции‑помощники для парсинга текстовых правил в объекты UFR​ule.
 * Предполагает, что все UFVariable уже созданы и переданы в словаре.
 */
UCLASS()
class FUZZYENGINE_API URuleParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Разбирает одну строку IF‑THEN и создаёт полностью настроенный UFR​ule */
	UFUNCTION(BlueprintCallable, Category = "Fuzzy|Rule")
		static UFRule* ParseRuleString(
			const FString& RuleText,
			const TMap<FString, UFVariable*>& Variables);
};