#include <QCoreApplication>
#include <QtCore/QDebug>

enum State {
	IntegerPartDigitState
	, PointState
	, FractionalPartDigitState
	, StartState
	, EndState
	, WrongSymbolState
};

State currentState = StartState;

bool isDigit(QChar const symbol)
{
	return ((symbol >= '0') && (symbol <= '9'));
}

bool isEndSymbol(QChar const symbol)
{
	return (symbol == '-');
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString const number = "12345.1234-";

	for (int i = 0; i < number.length(); ++i) {
		QChar symbol = number[i];
		switch (currentState)
		{
		case IntegerPartDigitState:
			if (symbol == '.') {
				currentState = PointState;
			} else if (isDigit(symbol)) {
				currentState = IntegerPartDigitState;
			} else if (isEndSymbol(symbol)){
				qDebug() << "Number is parsed";
				currentState = EndState;
			} else {
				qDebug() << "Fail in " << symbol;
				currentState = WrongSymbolState;
			}
			break;

		case PointState:
			if (isDigit(symbol)) {
				currentState = FractionalPartDigitState;
			} else {
				qDebug() << "Fail in " << symbol;
				currentState = WrongSymbolState;
			}
			break;

		case FractionalPartDigitState:
			if (isDigit(symbol)) {
				currentState = FractionalPartDigitState;
			} else if (isEndSymbol(symbol)) {
				qDebug() << "Number is parsed";
				currentState = EndState;
			} else {
				qDebug() << "Fail in " << symbol;
				currentState = WrongSymbolState;
			}
			break;

		case EndState:
			currentState = StartState;
			break;

		case StartState:
			if (isDigit(symbol)) {
				currentState = IntegerPartDigitState;
			} else {
				qDebug() << "Fail in " << symbol;
				currentState = WrongSymbolState;
			}
			break;

		case WrongSymbolState:
			currentState = StartState;
			break;
		}
	}
}
