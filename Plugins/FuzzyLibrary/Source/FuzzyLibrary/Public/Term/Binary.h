// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Term/Term.h"
#include "Binary.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FUZZYLIBRARY_API UBinary : public UTerm
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Membership")
	int32 Point;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Membership")
	bool bClosed = false;

	virtual void MakeRange() override;

	void Set(
		FString NameOther,
		int32 LowerBoundOther,
		int32 UpperBoundOther,
		int32 PointOther,
		bool IsClosed = true
	);
};
