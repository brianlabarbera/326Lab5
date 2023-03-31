#include <iostream>
#include "ArrStack.h"
#include "PoiStack.h"


int main() {

	ArrStack eval;

	char postfix[10] = {'3','5','+'};

	std::cout << eval.postfixEval(postfix);

	return 0;
}