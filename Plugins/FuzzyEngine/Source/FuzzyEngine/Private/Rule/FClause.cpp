#include "Rule/FClause.h"
#include "Variable/FVariable.h"
#include "Term/UTerm.h"
#include "Modifier/UModifier.h"

float FClause::Evaluate() const
{
	if (!Variable || !Term)
	{
		return 0.f;
	}

	float Mu = Term->Evaluate(Variable->GetInput());

	// применяем модификаторы по порядку
	for (const TObjectPtr<UModifier>& Mod : Modifiers)
	{
		if (Mod)
		{
			Mu = Mod->Modify(Mu);
		}
	}
	return Mu;
}
