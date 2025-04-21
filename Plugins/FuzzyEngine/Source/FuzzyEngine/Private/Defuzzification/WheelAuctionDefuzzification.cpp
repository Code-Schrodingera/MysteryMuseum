#include "Defuzzification/WheelAuctionDefuzzification.h"

float UWheelAuctionDefuzzification::Defuzzify_Implementation(const TArray<float>& X, const TArray<float>& Mu) const
{
    const int32 N = FMath::Min(X.Num(), Mu.Num());
    if (N == 0) return 0.f;

    float Total = 0.f;
    for (int32 i = 0; i < N; ++i) Total += Mu[i];
    if (Total <= KINDA_SMALL_NUMBER) return 0.f;

    const float R = FMath::FRandRange(0.f, Total);
    float Accum = 0.f;
    for (int32 i = 0; i < N; ++i)
    {
        Accum += Mu[i];
        if (Accum >= R) return X[i];
    }
    return X.Last();
}