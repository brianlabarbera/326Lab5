#include <iostream>
#include "ArrStack.h"
#include "PoiStack.h"


int main() {

	ArrStack eval;

	char infix[10] = {'(','a','+', 'b', ')', '*', 'c'};

	eval.infixtoPostfix(infix);

	return 0;
}