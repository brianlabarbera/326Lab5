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

	int i = 0, j = 0;

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