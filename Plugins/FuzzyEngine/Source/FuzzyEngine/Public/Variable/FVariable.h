#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Term/CrispCond.h"
#include "Variable/TermEntry.h"
#include "FVariable.generated.h"

class UTerm;

/** Нечёткая переменная (универсум float) */
UCLASS(Blueprintable, EditInlineNew, BlueprintType)
class FUZZYENGINE_API UFVariable : public UObject
{
    GENERATED_BODY()
public:
    /* ===================  Blueprint API  =================== */
    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    void SetInput(float Crisp) { InputValue = Crisp; }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fuzzy|Variable")
    float GetInput() const { return InputValue; }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fuzzy|Variable")
    float GetUniverseMin() const { return UniverseMin; }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fuzzy|Variable")
    float GetUniverseMax() const { return UniverseMax; }


    /** Ищем термы */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fuzzy|Variable")
    UTerm* FindTermByName(const FString& Name) const;


    /* Добавляем термы */
    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    UTerm* AddTriangularTerm(const FString& Name, float A, float B, float C);

    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    UTerm* AddTrapezoidTerm(const FString& Name, float A, float B, float C, float D);

    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    UTerm* AddGaussianTerm(const FString& Name, float Mean, float Sigma);

    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    UTerm* AddRandomTerm(const FString& Name);

    UFUNCTION(BlueprintCallable, Category = "Fuzzy|Variable")
    UTerm* AddCrispTerm(const FString& Name, float Threshold, CrispCond CrispCondition);


    /* ----------------  Editable  ---------------- */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Variable")
        float UniverseMin = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Variable")
        float UniverseMax = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuzzy|Variable")
        TArray<FTermEntry> Terms;

private:
    /** Crisp‑значение */
    float InputValue = 0.f;
};