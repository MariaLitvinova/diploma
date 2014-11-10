#pragma once

#include <QtCore/QString>
#include <QtCore/QList>

namespace stateDiagram {

class State
{
public:
	State(QString const &displayedName, QString const &type);

	QString name() const;
	QString type() const;

	bool operator == (State anotherState);

private:
	QString mName;
	QString mType;

	QList<State> mToStates;
};
}
