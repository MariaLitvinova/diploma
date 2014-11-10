#include "transition.h"

using namespace stateDiagram;

Transition::Transition(State const &startState
		, State const &endState
		, QChar const &symbol
	) :
	mStartState(startState)
	, mEndState(endState)
	, mSymbol(symbol)
{
}

State Transition::startState() const
{
	return mStartState;
}

State Transition::endState() const
{
	return mEndState;
}

QChar Transition::symbol() const
{
	return mSymbol;
}

bool Transition::operator ==(Transition anotherTransition)
{
	return (mStartState == anotherTransition.startState()
			&& mEndState == anotherTransition.endState()
			&& mSymbol == anotherTransition.symbol()
			);
}
