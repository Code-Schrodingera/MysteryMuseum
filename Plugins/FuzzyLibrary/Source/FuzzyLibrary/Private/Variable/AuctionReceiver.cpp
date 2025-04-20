// Fill out your copyright notice in the Description page of Project Settings.


#include "Variable/AuctionReceiver.h"
#include "Kismet/KismetMathLibrary.h"

FString UAuctionReceiver::Receive(TMap<FString, float> List)
{
	TArray<float> AuctionFloat;
	TArray<FString> AuctionNames;

	float MaxValue = 0;

	for (auto& Elem : List)
	{
		AuctionNames.Push(Elem.Key);
		AuctionFloat.Push(MaxValue);

		MaxValue += Elem.Value;
	}

	float RandValue = UKismetMathLibrary::RandomFloatInRange(0, MaxValue);

	for (int32 Index = AuctionFloat.Num() - 1; Index >= 0; --Index)
	{
		if (AuctionFloat[Index] <= RandValue)
		{
			return AuctionNames[Index];
		}
	}

	return AuctionNames[0];

}