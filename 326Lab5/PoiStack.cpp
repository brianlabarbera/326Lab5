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

PoiStack::~PoiStack() {

	while (top) {
		Node* delNode = top;
		
		top = top->next;

		delete delNode;
	}

}