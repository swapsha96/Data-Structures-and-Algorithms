#include <iostream>
#include "stack.hpp"

int main() {
	cs202::stack<int> *stack = new cs202::stack<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->pop();
	stack->print();
	return 0;
}