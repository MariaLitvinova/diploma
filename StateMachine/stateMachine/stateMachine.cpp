#include "stateMachine.h"

#include <QtCore/QDebug>

using namespace stateDiagram;

StateMachine::StateMachine(QString const &inputString
		, QList<State> states
		, QList<Transition> transitions
		, State startState
		, State endState
	)
{
	State currentState = startState;
	bool fail = true;
	bool transitionFound = false;
	int currentSymbolIndex = 1;

	for (const QChar currentSymbol : inputString) {
		transitionFound  = false;

		foreach (State possibleState, states) {
			Transition transition(currentState, possibleState, currentSymbol);

			if (transitions.contains(transition)) {
				currentState = possibleState;
				transitionFound = true;

				qDebug() << transition.symbol();
				if (currentState == endState && currentSymbolIndex == inputString.length()) {
					fail = false;
				}
				break;
			}
		}
		if (!transitionFound) {
			break;
		}

		currentSymbolIndex++;
	}

	if (fail) {
		qDebug() << "Fail";
	} else {
		qDebug() << "Win";
	}
}
