#include "Variable/FVariable.h"
#include "Term/Forms/TriangularTerm.h"
#include "Term/Forms/TrapezoidTerm.h"
#include "Term/Forms/GaussianTerm.h"

UTerm* UFVariable::GetTermByName(const FString& Name) const
{
    for (const FTermEntry& Entry : Terms)
    {
        if (Entry.Name.Equals(Name, ESearchCase::IgnoreCase) && Entry.Term)
        {
            return Entry.Term;
        }
    }
    return nullptr;
}

UTerm* UFVariable::AddTriangularTerm(const FString& InName, float A, float B, float C)
{
    auto* T = NewObject<UTriangularTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C;
    Terms.Add({ InName, T });
    return T;
}

UTerm* UFVariable::AddTrapezoidTerm(const FString& InName, float A, float B, float C, float D)
{
    auto* T = NewObject<UTrapezoidTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C; T->D = D;
    Terms.Add({ InName, T });
    return T;
}

UTerm* UFVariable::AddGaussianTerm(const FString& InName, float Mean, float Sigma)
{
    auto* T = NewObject<UGaussianTerm>(this, NAME_None, RF_Transactional);
    T->Mean = Mean; T->Sigma = Sigma;
    Terms.Add({ InName, T });
    return T;
}