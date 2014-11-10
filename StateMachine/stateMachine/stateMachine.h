#pragma once

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "state.h"
#include "transition.h"

namespace stateDiagram {

class StateMachine
{
public:
	StateMachine(QString const &inputString
			, QList<State> states
			, QList<Transition> transitions
			, State startState
			, State endState
			);

private:
};
}
