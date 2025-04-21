#include "Variable/FVariable.h"
#include "Term/ITerm.h"
#include "Term/TriangularTerm.h"
#include "Term/TrapezoidTerm.h"
#include "Term/GaussianTerm.h"
#include "Term/RandomTerm.h"
#include "Term/CrispTerm.h"

UTerm* UFVariable::FindTermByName(const FString& Name) const
{
    for (const FTermEntry& Entry : Terms)
    {
        if (Entry.Name.Equals(Name, ESearchCase::IgnoreCase) && Entry.Term)
        {
            return Cast<UTerm>(Entry.Term.GetObject());
        }
    }
    return nullptr;
}

UTerm* UFVariable::AddTriangularTerm(const FString& Name, float A, float B, float C)
{
    auto* T = NewObject<UTriangularTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C;
    Terms.Add(FTermEntry{ Name, T });
    return Cast<UTerm>(T);
}

UTerm* UFVariable::AddTrapezoidTerm(const FString& Name, float A, float B, float C, float D)
{
    auto* T = NewObject<UTrapezoidTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C; T->D = D;
    Terms.Add({ Name, T });
    return Cast<UTerm>(T);
}

UTerm* UFVariable::AddGaussianTerm(const FString& Name, float Mean, float Sigma)
{
    auto* T = NewObject<UGaussianTerm>(this, NAME_None, RF_Transactional);
    T->Mean = Mean; T->Sigma = Sigma;
    Terms.Add({ Name, T });
    return Cast<UTerm>(T);
}

UTerm* UFVariable::AddCrispTerm(const FString& Name, float Threshold, CrispCond CrispCondition)
{
    auto* T = NewObject<UCrispTerm>(this, NAME_None, RF_Transactional);
    T->Threshold = Threshold;
    T->CrispCondition = CrispCondition;
    Terms.Add({ Name, T });
    return Cast<UTerm>(T);
}

UTerm* UFVariable::AddRandomTerm(const FString& Name)
{
    auto* T = NewObject<UGaussianTerm>(this, NAME_None, RF_Transactional);
    Terms.Add({ Name, T });
    return Cast<UTerm>(T);
}