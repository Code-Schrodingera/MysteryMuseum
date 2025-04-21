#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Aggregation/IAggregation.h"
#include "Activation/IActivation.h"
#include "Accumulation/IAccumulation.h"
#include "Defuzzification/IDefuzzification.h"
#include "FEngine.generated.h"

class UFVariable;
class UFR​ule;

/**
 * Central orchestrator: собирает входы, применяет правила,
 * аккумулирует MF и дефаззифицирует результат.
 */
UCLASS(BlueprintType, EditInlineNew)
class FUZZYENGINE_API UFEngine : public UObject
{
	GENERATED_BODY()

public:
	/** Переменные (inputs + output universe) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Fuzzy")
	TArray<UFVariable*> Variables;

	/** Правила */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Fuzzy")
	TArray<UFRule*> Rules;

	/** Агрегатор AND (по‑дефолту Min) */
	UPROPERTY(EditAnywhere, Category = "Fuzzy")
	TScriptInterface<IAggregation> AndAggregation;

	/** Агрегатор OR (по‑дефолту Max) */
	UPROPERTY(EditAnywhere, Category = "Fuzzy")
	TScriptInterface<UAggregation> OrAggregation;

	/** Активатор (по‑дефолту Prod) */
	UPROPERTY(EditAnywhere, Category = "Fuzzy")
	TScriptInterface<UActivation> Activation;

	/** Аккумулятор (по‑дефолту Max) */
	UPROPERTY(EditAnywhere, Category = "Fuzzy")
	TScriptInterface<UAccumulation> Accumulation;

	/** Дефаззификатор (по‑дефолту WheelAuction) */
	UPROPERTY(EditAnywhere, Category = "Fuzzy")
	TScriptInterface<UDefuzzification> Defuzzification;

public:
	UFEngine();

	/** Перед вызовом установите Crisp‑значения переменных, затем получите результат */
	UFUNCTION(BlueprintCallable, Category = "Fuzzy")
		float Evaluate();
};