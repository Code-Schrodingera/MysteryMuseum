// Fill out your copyright notice in the Description page of Project Settings.


#include "Term/Quadratic.h"

void UQuadratic::MakeRange()
{
	Super::MakeRange();

	int32 termA, termB;
	termA = PointA - LowerBound;
	termB = PointB - LowerBound;

	for (int32 Index = 0; Index < ValueRange.Num(); ++Index)
	{
		if (Index < termA || Index > termB)
		{
			ValueRange[Index] = 0.0f;
		}
		else
		{
			ValueRange[Index] = FMath::Square((Index - termA) * 1.0f / (termB - termA));
		}
	}
}

void UQuadratic::Set(
	FString NameOther,
	int32 LowerBoundOther,
	int32 UpperBoundOther,
	int32 PointAOther,
	int32 PointBOther
)
{
	Super::Set(NameOther, LowerBoundOther, UpperBoundOther);

	PointA = PointAOther;
	PointB = PointBOther;
}
