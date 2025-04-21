#include "Rule/RuleParser.h"
#include "Rule/FRule.h"
#include "Rule/FClause.h"
#include "Variable/FVariable.h"
#include "Modifier/Modifier.h"
#include "Term/ITerm.h"

UFRule* URuleParser::ParseRuleString(
	const FString& RuleText,
	const TMap<FString, UFVariable*>& Variables)
{
	// *** Мини‑реализация ***:
	// Для краткости: split'им, ищем IF/THEN, оперируем «AND/OR».
	// В прод‑коде стоит написать полноценный лексер.
	UFRule* Rule = NewObject<UFRule>();

	TArray<FString> Tokens;
	RuleText.ParseIntoArrayWS(Tokens);

	int32 Index = 0;
	auto Peek = [&]() -> FString { return (Index < Tokens.Num()) ? Tokens[Index] : FString(); };
	auto Next = [&]() -> FString { return (Index < Tokens.Num()) ? Tokens[Index++] : FString(); };

	if (!Next().Equals(TEXT("IF"), ESearchCase::IgnoreCase))
	{
		return Rule;
	}

	// --- Antecedent ---
	while (Index < Tokens.Num())
	{
		FClause Clause;

		// Variable
		const FString VarName = Next();
		UFVariable* const* VarPtr = Variables.Find(VarName);
		if (!VarPtr) { return Rule; }
		Clause.Variable = *VarPtr;

		if (!Next().Equals(TEXT("IS"), ESearchCase::IgnoreCase)) { return Rule; }

		// Modifiers (NOT, VERY, APPROX)
		while (Peek().Equals(TEXT("NOT"), ESearchCase::IgnoreCase) ||
			Peek().Equals(TEXT("VERY"), ESearchCase::IgnoreCase) ||
			Peek().Equals(TEXT("APPROX"), ESearchCase::IgnoreCase))
		{
			const FString ModTok = Next();
			UModifier* ModObj = UModifier::CreateFromToken(ModTok); // стат. фабрика в вашем классе
			if (ModObj)
			{
				Clause.Modifiers.Add(ModObj);
			}
		}

		// Term
		const FString TermName = Next();
		Clause.Term = Clause.Variable->FindTermByName(TermName);

		// Оп с следующей
		if (Peek().Equals(TEXT("AND"), ESearchCase::IgnoreCase))
		{
			Clause.OpWithNext = EOp::AND; Next();
		}
		else if (Peek().Equals(TEXT("OR"), ESearchCase::IgnoreCase))
		{
			Clause.OpWithNext = EOp::OR; Next();
		}
		else
		{
			Clause.OpWithNext = EOp::AND; // по умолчанию
		}

		Rule->Clauses.Add(Clause);

		if (Peek().Equals(TEXT("THEN"), ESearchCase::IgnoreCase))
		{
			Next();
			break;
		}
	}

	// --- Consequent ---
	// «VariableLast IS TermLast»
	if (Tokens.IsValidIndex(Index + 2))
	{
		const FString VarName = Tokens[Index++];
		const FString IsTok = Tokens[Index++];
		const FString TermName = Tokens[Index++];

		UFVariable* const* VarPtr = Variables.Find(VarName);
		if (VarPtr && (*VarPtr)->FindTermByName(TermName))
		{
			Rule->ConsequentTerm = (*VarPtr)->FindTermByName(TermName);
		}
	}

	return Rule;
}