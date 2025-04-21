#include "Defuzzification/MaxMembershipDefuzzification.h"

float UMaxMembershipDefuzzification::Defuzzify_Implementation(const TArray<float>& X, const TArray<float>& Mu) const
{
    float MaxMu = -1.f; float MaxX = 0.f;
    const int32 N = FMath::Min(X.Num(), Mu.Num());
    for (int32 i = 0; i < N; ++i)
    {
        if (Mu[i] > MaxMu)
        {
            MaxMu = Mu[i];
            MaxX = X[i];
        }
    }
    return MaxX;
}