#include<iostream>
using namespace std;

#include"Stack.h"
#include"calculator.h"

int main()
{


	string infix_expression;
	int ch, size;
	do
	{

		cout << " Enter an infix expression: ";
		getline(cin, infix_expression);

		string* strPtr = convert(infix_expression, size);
		cout << "postfix: ";
		for (int i = 0; i < size; i++) {
			cout << strPtr[i];
		}
		cout << endl;
		//	cout << "postfix expression:  " << postfix_expression << endl;
		cout << "the result is:  " << ComputePostfix(strPtr, size) << endl;

		cout << "again ? click 1 ";
		cin >> ch;
	} while (ch == 1);

	return 0;
}
