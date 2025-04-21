#include "Rule/FClause.h"
#include "Variable/FVariable.h"
#include "Term/ITerm.h"
#include "Modifier/Modifier.h"

float FClause::Evaluate() const
{
    if (!Variable || !Term) { return 0.f; }

    float Mu = ITerm::Execute_Evaluate(Term.GetObject(), Variable->GetInput());
    for (UModifier* Mod : Modifiers)
    {
        if (Mod) { Mu = Mod->Apply(Mu); }
    }
    return Mu;
}
