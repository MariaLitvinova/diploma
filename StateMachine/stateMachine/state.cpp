#include "state.h"
#include "defs.h"

using namespace stateDiagram;

State::State(QString const &displayedName, QString const &type) :
	mName(displayedName)
	, mType(type)
{
}

QString State::name() const
{
	return mName;
}

QString State::type() const
{
	return mType;
}

bool State::operator ==(State anotherState)
{
	return (mType == anotherState.type() && mName == anotherState.name());
}
