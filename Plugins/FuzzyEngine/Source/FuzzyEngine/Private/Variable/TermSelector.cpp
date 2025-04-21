#include "Variable/TermSelector.h"
#include "Variable/FVariable.h"
#include "Term/Term.h"

FString UTermSelector::SelectTerm(UFVariable* Var, float Crisp) const
{
    if (!Var) return "NO VARIABLE";

    float BestMu = -1.f;
    FString BestTerm = "";

    for (const auto& Entry : Var->Terms)
    {
        if (!Entry.Term) continue;
        
        float Mu = Entry.Term->Evaluate(Crisp);
        if (Mu > BestMu)
        {
            BestMu = Mu;
            BestTerm = Entry.Name;
        }
    }

    return BestTerm;
}
