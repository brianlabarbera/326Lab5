#include "PoiStack.h"
#include <iostream>


void PoiStack::push(int x) {

	Node* t = new Node;

	t->data = x;
	t->next = top;

	top = t;
}

void PoiStack::pop(int& x, bool& success) {
	success = top != 0;

	if (success) {
		x = top->data;

		Node* delNode = top;
		
		top = top->next;
		
		delete delNode;
	}
}

void PoiStack::getTop(int& x, bool& success) {
	success = top != 0;

	if (success) {
		x = top->data;
	}

}

bool PoiStack::isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return true;
	}

	else { return false; }
}

bool PoiStack::isOperand(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else { return false; }
}

float PoiStack::operation(int a, int b, char op) {

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

float PoiStack::postfixEval(char postfix[]) {

	bool success;

	int i = 0, j = 0;

	int op2;
	int op1;
	int op;

	while (postfix[i] != '\0') {

		if (isOperand(postfix[i])) {
			push(postfix[i] - '0');
		}

		else if (isOperator(postfix[i])) {

			pop(op2, success);
			pop(op1, success);

			op = operation(op1, op2, postfix[i]);

			push(op);

		}

		i++;

	}

	return op;

}



PoiStack::~PoiStack() {

	while (top) {
		Node* delNode = top;
		
		top = top->next;

		delete delNode;
	}

}