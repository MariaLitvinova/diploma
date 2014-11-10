#include <QCoreApplication>

#include "stateMachine.h"

#include <QtCore/QString>
#include <QtCore/QChar>
#include <QtCore/QStringList>
#include <QtCore/QDebug>

using namespace stateDiagram;

QList<State> generatedStates()
{
	QList<State> result;

	result << State("S0", "Start");
	result << State("S1", "Usual");
	result << State("S2", "Usual");
	result << State("S3", "Usual");
	result << State("S4", "Usual");
	result << State("S5", "End");

	return result;
}

QList<Transition> generatedTransitions()
{
	QList<Transition> result;

	result << Transition(State("S0", "Start"), State("S1", "Usual"), 'a');
	result << Transition(State("S1", "Usual"), State("S2", "Usual"), 'b');
	result << Transition(State("S2", "Usual"), State("S3", "Usual"), 'b');
	result << Transition(State("S3", "Usual"), State("S5", "End"), 'a');
	result << Transition(State("S2", "Usual"), State("S4", "Usual"), 'a');
	result << Transition(State("S4", "Usual"), State("S3", "Usual"), 'b');

	return result;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QList<State> states = generatedStates();
	QList<Transition> transitions = generatedTransitions();

	QString const &string = "abbbabc";

	StateMachine(string, states, transitions, State("S0", "Start"), State("S5", "End"));

	return a.exec();
}
