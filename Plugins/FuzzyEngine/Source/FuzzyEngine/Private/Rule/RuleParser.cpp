#include "Rule/RuleParser.h"
#include "Rule/FRule.h"
#include "Rule/FClause.h"
#include "Variable/FVariable.h"
#include "Modifier/Modifier.h"
#include "Norms/TNorms/ProbTNorm.h"
#include "Norms/SNorms/ProbSNorm.h"
#include "Term/Term.h"

UFRule* URuleParser::ParseRuleString(
	const FString& RuleText,
	const TMap<FString, UFVariable*>& Variables)
{
	UFRule* Rule = NewObject<UFRule>();
	Rule->TNormOp = NewObject<UProbTNorm>(Rule);
	Rule->SNormOp = NewObject<UProbSNorm>(Rule);

	TArray<FString> Tokens;
	RuleText.ParseIntoArrayWS(Tokens);

	int32 Index = 0;
	auto Peek = [&]() -> FString { return (Index < Tokens.Num()) ? Tokens[Index] : FString(); };
	auto Next = [&]() -> FString { return (Index < Tokens.Num()) ? Tokens[Index++] : FString(); };
	auto LastToken = Tokens.Last();

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
			UModifier* ModObj = UModifier::CreateFromToken(ModTok);
			if (ModObj)
			{
				Clause.Modifiers.Add(ModObj);
			}
		}

		const FString TermName = Next();
		Clause.Term = Clause.Variable->FindTermByName(TermName);

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
			Clause.OpWithNext = EOp::AND;
		}

		Rule->Clauses.Add(Clause);

		if (Peek().Equals(TEXT("THEN"), ESearchCase::IgnoreCase))
		{
			Next();
			break;
		}
	}

	// --- Consequent ---
	if (Tokens.IsValidIndex(Index + 2))
	{
		FString CoVarName = Tokens[Index++];
		FString CoIsTok = Tokens[Index++];
		FString CoTermName = LastToken;

		UFVariable* const* VarPtr = Variables.Find(CoVarName);
		if (VarPtr && (*VarPtr)->FindTermByName(CoTermName))
		{
			Rule->ConsequentTerm = (*VarPtr)->FindTermByName(CoTermName);
		}
	}

	return Rule;
}