#include "Rule/FClause.h"
#include "Variable/FVariable.h"
#include "Term/Term.h"
#include "Modifier/Modifier.h"

float FClause::Evaluate() const
{
    if (!Variable || !Term) { return 0.f; }

    float Mu = Term ? Term->Evaluate(Variable->GetInput()) : 0.f;
    for (UModifier* M : Modifiers)
    {
        Mu = M->Apply(Mu);
    }
    return Mu;
}
