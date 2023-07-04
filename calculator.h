#include<iostream>
#include"Stack.h"
#include<string>
using namespace std;

bool isOperator(string str) {
	if (str == "+" || str == "-" || str == "*" || str == "/" || str == "^")
		return true;
	return false;
}

bool isOperand(string str) {
	if (str >= "a" && str <= "z")
		return true;
	if (str >= "A" && str <= "Z")
		return true;
	if (str >= "0" && str <= "9999")
		return true;
	return false;
}

int precedence(string op) {
	if (op == "+" || op == "-")
		return 1;
	if (op == "*" || op == "/")
		return 2;
	if (op == "^")
		return 3;
	return 0;
}

bool isnewEqualOrLower(string Last, string New) {
	int lastpreced = precedence(Last);
	int newpreced = precedence(New);

	if (lastpreced == newpreced) {
		if (New == "^") //
			return false;
		return true;
	}
	return(newpreced < lastpreced);
}

string* str2arrstr(string infix,int &length) {
	int j = 0;
	string* arr = new string[100];
	string number, digit;
	for (int i = 0; i < infix.length(); i++) {

		digit = infix[i];
		if (isOperand(digit))
			number += infix[i];
		else if (isOperator(digit)) {
			arr[j] = number;
			j++;
			arr[j] = infix[i];
			j++;
			number.clear();
		}
		else if (!number.empty()) {
			arr[j] = number;
			j++;
			number.clear();
			if (infix[i] == '(' || infix[i] == ')') {
				arr[j] = infix[i];
				j++;
			}
		}
		else if (infix[i] == '(' || infix[i] == ')') {
			arr[j] = infix[i];
			j++;
		}
		if (infix.length() == i + 1)
			if (!number.empty()) {
				arr[j] = number;
				j++;
				number.clear();
			}
	}

	length = j + 1;
	return arr;
}

string* convert(string infix, int& size)
{
	size = 0;
	int length;
	string* arr = str2arrstr(infix, length);
	stack<string>s;
	string str;
	s.push("(");
	arr[length-1] = ")";
	
	string* postfix = new string[length];
	for (int i = 0; i < length; i++) {
		str = arr[i];
		if (str == " ")
			continue;

		else if (str == "(")
			s.push(str);

		else if (isOperand(str)) {
			postfix[size] = str;
			size++;
		}
		else if (isOperator(str)) {
			while (!s.isEmpty() && isnewEqualOrLower(s.peek(), str)) {
				// NO need for --->   (...s.peek() != '(' &&....) 
			   //cause in this case isnewEqualorlower return false
				postfix[size] = s.pop();
				size++;
			}
			s.push(str);
		}
		else if (str == ")") {
			while (!s.isEmpty() && s.peek() != "(") {

				postfix[size] = s.pop();
				size++;
			}
			s.pop();
		}
	}
	return postfix;
}

int ComputePostfix(string* postfix, int size) {
	stack<string>s;
	string str;
	int n1, n2;
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		str = postfix[i];
		if (isOperand(str))
			s.push(str);

		else if (isOperator(str)) {

			n2 = stoi(s.pop());
			n1 = stoi(s.pop());

			if (postfix[i] == "+")
				s.push(to_string(n1 + n2));
			else if (postfix[i] == "-")
				s.push(to_string(n1 - n2));
			else if (postfix[i] == "*")
				s.push(to_string(n1 * n2));
			else if (postfix[i] == "/")
				s.push(to_string(n1 / n2));
			else if (postfix[i] == "^")
				s.push(to_string(pow(n1, n2)));
		}
	}
	return stoi(s.pop());
}
