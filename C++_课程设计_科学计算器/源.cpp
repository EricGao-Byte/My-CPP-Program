#include <iostream>
#include "calculator.h"
#include "stack.h"
using namespace std;

int main()
{
	Calculator<double> cal;
	cal.inputMidfix();
	cal.printMidfix();
	cal.convertMidfix();
	cal.printPostfix();
	return 0;
}