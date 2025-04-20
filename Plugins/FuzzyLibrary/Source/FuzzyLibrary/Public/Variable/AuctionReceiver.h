// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Variable/VariableReceiver.h"
#include "AuctionReceiver.generated.h"

/**
 * 
 */
UCLASS()
class FUZZYLIBRARY_API UAuctionReceiver : public UVariableReceiver
{
	GENERATED_BODY()
	
public:
	virtual FString Receive(TMap<FString, float> List) override;

};
