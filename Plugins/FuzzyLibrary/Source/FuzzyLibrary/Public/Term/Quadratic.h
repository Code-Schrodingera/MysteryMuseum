// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Term/Term.h"
#include "Quadratic.generated.h"

/**
 * 
 */
UCLASS()
class FUZZYLIBRARY_API UQuadratic : public UTerm
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Membership")
	int32 PointA;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Membership")
	int32 PointB;

	virtual void MakeRange() override;

	void Set(
		FString NameOther,
		int32 LowerBoundOther,
		int32 UpperBoundOther,
		int32 PointAOther,
		int32 PointBOther
	);
};
