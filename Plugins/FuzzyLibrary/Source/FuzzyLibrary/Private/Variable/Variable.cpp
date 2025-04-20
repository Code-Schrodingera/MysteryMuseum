// Fill out your copyright notice in the Description page of Project Settings.


#include "Variable/Variable.h"
#include "Containers/Map.h"

void UVariable::UpdateDegreeOfMembership(int32 x)
{
	LastValue.Empty();

	for (auto& Elem : Terms)
	{
		LastValue.Add(Elem.Key, Elem.Value->GetDegreeOfMembership(x));
	}

}

void UVariable::AddTerm(FString TermName, UTerm* NewTerm, int32 Weight)
{
	NewTerm->MakeRange();
	Terms.Add(TermName, NewTerm);
	WeightsForTerms.Add(TermName, Weight);
}

UTerm* UVariable::GetTermFromMapByName(const FString& TargetTermName)
{
	if (!Terms.Contains(TargetTermName)) return nullptr;

	return Terms[TargetTermName];
}

float UVariable::GetValueFromMapByName(const FString& TargetTermName)
{
	if (!LastValue.Contains(TargetTermName)) return 0.0f;

	return LastValue[TargetTermName];
}

FString UVariable::GetTermWithValue(int32 x)
{
	UpdateDegreeOfMembership(x);
	auto WeightedValue = LastValue;
	for (auto& Elem : WeightedValue)
	{
		WeightedValue[Elem.Key] *= WeightsForTerms[Elem.Key];
	}
	return Receiver->Receive(LastValue);

}

TMap<FString, int32> UVariable::GetXFromDegree(const float Degree)
{
	TMap<FString, int32> XArray;
	for (auto& Elem : Terms)
	{
		int32 MostSimilarValue = Elem.Value->LowerBound;
		float SmallestError = FMath::Square(Degree - Elem.Value->GetDegreeOfMembership(MostSimilarValue));

		for (int Value = Elem.Value->LowerBound; Value <= Elem.Value->UpperBound; ++Value)
		{
			float NewError = FMath::Square(Degree - Elem.Value->GetDegreeOfMembership(Value));

			if (NewError <= SmallestError)
			{
				SmallestError = NewError;
				MostSimilarValue = Value;
			}
		}

		XArray.Add(Elem.Key, MostSimilarValue);
	}

	return XArray;
}

void UVariable::ClearTerms()
{
	Terms.Empty();

}

void UVariable::Set(
	FString NameOther,
	int32 LowerBoundOther,
	int32 UpperBoundOther,
	UVariableReceiver* ReceiverOther
)
{
	Name = NameOther;
	LowerBound = LowerBoundOther;
	UpperBound = UpperBoundOther;
	Receiver = ReceiverOther;
	ClearTerms();
}
