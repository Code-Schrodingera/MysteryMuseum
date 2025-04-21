#include "Variable/FVariable.h"
#include "Term/TriangularTerm.h"
#include "Term/TrapezoidTerm.h"
#include "Term/GaussianTerm.h"

TScriptInterface<UTerm> UFVariable::FindTermByName(const FString& Name) const
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

TScriptInterface<UTerm> UFVariable::AddTriangularTerm(const FString& Name, float A, float B, float C)
{
    auto* T = NewObject<UTriangularTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C;
    Terms.Add({ Name, T });
    return T;
}

TScriptInterface<UTerm> UFVariable::AddTrapezoidTerm(const FString& Name, float A, float B, float C, float D)
{
    auto* T = NewObject<UTrapezoidTerm>(this, NAME_None, RF_Transactional);
    T->A = A; T->B = B; T->C = C; T->D = D;
    Terms.Add({ Name, T });
    return T;
}

TScriptInterface<UTerm> UFVariable::AddGaussianTerm(const FString& Name, float Mean, float Sigma)
{
    auto* T = NewObject<UGaussianTerm>(this, NAME_None, RF_Transactional);
    T->Mean = Mean; T->Sigma = Sigma;
    Terms.Add({ Name, T });
    return T;
}