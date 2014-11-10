#pragma once

#include <QtCore/QString>
#include <QtCore/QChar>

#include "state.h"

// Логика перехода
class Transition
{
public:
	Transition(stateDiagram::State const &startState
			, stateDiagram::State const &endState
			, QChar const &symbol
		);

	stateDiagram::State startState() const;
	stateDiagram::State endState() const;
	QChar symbol() const;

	bool operator == (Transition anotherTransition);

private:
	stateDiagram::State mStartState;
	stateDiagram::State mEndState;
	QChar mSymbol;
};
