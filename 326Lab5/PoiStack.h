#ifndef POISTACK_H
#define POISTACK_H

class PoiStack {

public:

     PoiStack():top(nullptr){}
	 void push(int x);
	 void pop(int& x, bool& success);
	 void getTop(int& x, bool& success);
	 ~PoiStack();
  

private:

	struct Node {
		int data;
		Node* next;
	};

	Node* top;

};

#endif