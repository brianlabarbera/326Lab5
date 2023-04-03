#include <iostream>
#include "ArrStack.h"
#include "PoiStack.h"

void problemChoice();
void problem1();
void problem2();
void problem3();

int main() {

	problemChoice();

	return 0;
}

void problemChoice() {

	int choice = 0;

	do {

		std::cout << "Enter 1 to evaluate a postfix expression using an array stack" << std::endl;

		std::cout << "or" << std::endl;

		std::cout << "Enter 2 to evaluate a postfix expression using a pointer stack" << std::endl;

		std::cout << "or" << std::endl;

		std::cout << "Enter 3 to convert infix to postfix" << std::endl;

		std::cin >> choice;

		std::cout << std::endl;

		if (choice == 1) {

			problem1();

		}

		if (choice == 2) {

			problem2();

		}

		if (choice == 3) {

			problem3();

		}

	} while (choice != 1 && choice != 2 && choice != 3);

}

void problem1() {

	ArrStack eval;

	char postfix[10] = { '3','5','+','6','*' };

	std::cout << eval.postfixEval(postfix);

}

void problem2() {

	PoiStack eval;

	char postfix[10] = { '3','5','+','6','*' };

	std::cout << eval.postfixEval(postfix);
	
}

void problem3() {

	ArrStack eval;

	char infix[10] = { '(','a','+', 'b', ')', '*', 'c' };

	eval.infixtoPostfix(infix);

}