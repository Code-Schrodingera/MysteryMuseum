#include "Variable/TermSelector.h"
#include "Variable/FVariable.h"
#include "Term/ITerm.h"

FString UTermSelector::SelectTerm(UFVariable* Var, float Crisp) const
{
    if (!Var) return "NO VARIABLE";

    float BestMu = -1.f;
    FString BestTerm = "";

    for (const auto& Entry : Var->Terms)
    {
        if (!Entry.Term) continue;
        // Evaluate принадлежность этого терма к Crisp
        float Mu = ITerm::Execute_Evaluate(Entry.Term.GetObject(), Crisp);
        if (Mu > BestMu)
        {
            BestMu = Mu;
            BestTerm = Entry.Name;
        }
    }

    return BestTerm;
}
