#ifndef POISTACK_H
#define POISTACK_H

class PoiStack {

public:

     PoiStack():top(nullptr){}
	 void push(int x);
	 void pop(int& x, bool& success);
	 void getTop(int& x, bool& success);
	 float postfixEval(char postfix[]);
	 bool isOperator(char ch);
	 bool isOperand(char ch);
	 float operation(int a, int b, char op);
	 ~PoiStack();
  

private:

	struct Node {
		int data;
		Node* next;
	};

	Node* top;

};

#endif