#include <iostream>
#include "calculator.h"
#include <string>

int main()
{
	Calculator* calculator = new Calculator;
	string expression;
	getline(cin, expression); //(ln(e) +2.1245)*3 + 3^3/2 + cos(cbrt(pi^3))
	expression.push_back('$'); //adding in the end stop symbol
	if (calculator->read(expression) == true)
	{
		cout << "Original: "; calculator->print_to_console();
		calculator->toPrefix();
		cout << "\nPrefix form: "; calculator->print_to_console();
		cout << "\nAnswer: " << calculator->calculate();
	}
	return 0;
}