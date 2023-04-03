#include "ArrStack.h"
#include <iostream>

void ArrStack::push(int x, bool& success) {
	success = top < max - 1;

	if (success) {
		++top;
		data[top] = x;
	}
}

void ArrStack::pop(int& x, bool& success) {
	success = top > -1;

	if (success) {
		x = data[top];
		top--;
	}
}

void ArrStack::getPop(int& x, bool& success) {
	success = top > -1;

	if (success) {
		x = data[top];
	}
}

int ArrStack::precendence(char op) {

	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}

}

float ArrStack::operation(int a, int b, char op) {
	
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return b / a;
	else if (op == '^')
		return pow(b, a); 
	else
		return INT_MIN; 
}

bool ArrStack::isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return true;
	}

	else { return false; }
}

bool ArrStack::isOperand(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else { return false; }
}

int ArrStack::postfixEval(char postfix[]) {
	bool success;

	int i = 0;

	int op2;
	int op1;
	int op;

	while (postfix[i] != '\0') {

		if (isOperand(postfix[i])) {
			push(postfix[i] - '0', success);
		}

		else if (isOperator(postfix[i])) {

			pop(op2, success);
			pop(op1, success);
			
			op = operation(op1, op2, postfix[i]);

			push(op, success);

		}
		i++;
	}

	return op;
}

void ArrStack::infixtoPostfix(char infix[]) {

	bool success;

	std::string result;

	int i = 0;
	int num = 0;

	while (infix[i] != '\0') {

		char temp = infix[i];

		i++;

		if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')
			|| (temp >= '0' && temp <= '9')) {
			result += temp;
		}

		else if (temp == '(') {
			push('(', success);
		}

		else if (temp == ')') {

			pop(num, success);

			while (top > -1 && num != '(') {
				result += num;
				pop(num, success);
			}
		}

		else {

			getPop(num, success);

			while (top > -1 && precendence(temp) <= precendence(num)) {

				result += num;

				pop(num, success);

			}

			push(temp, success);


		}

	}

	while (top > -1) {


		pop(num, success);
		result += num;


	}

	std::cout << result << std::endl;

}