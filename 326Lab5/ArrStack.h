#ifndef ARRSTACK_H
#define ARRSTACK_H

const int max = 10;

class ArrStack {

public:

	ArrStack():top(-1) {};
	void push(int x, bool &success);
	void pop(int& x, bool &success);
	void getPop(int& x, bool& success);
	int postfixEval(char postfix[]);
	bool isOperator(char ch);
	bool isOperand(char ch);
	float operation(int a, int b, char op);

private:
	int data[max];
	int top;
	


};

#endif