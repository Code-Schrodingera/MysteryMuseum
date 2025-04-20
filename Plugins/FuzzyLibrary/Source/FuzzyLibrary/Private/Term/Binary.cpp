// Fill out your copyright notice in the Description page of Project Settings.


#include "Term/Binary.h"

void UBinary::MakeRange()
{
	Super::MakeRange();

	int tempPoint = Point - LowerBound;

	for (int32 Index = 0; Index < ValueRange.Num(); ++Index)
	{
		if (Index < tempPoint)
		{
			ValueRange[Index] = 1;
		}
		else if (Index == tempPoint && !bClosed)
		{
			ValueRange[Index] = 1;
		}
		else
		{
			ValueRange[Index] = 0;
		}
	}
}

void UBinary::Set(FString NameOther,
	int32 LowerBoundOther,
	int32 UpperBoundOther,
	int32 PointOther,
	bool IsClosed)
{
	Super::Set(NameOther, LowerBoundOther, UpperBoundOther);

	Point = PointOther;
	bClosed = IsClosed;
}
