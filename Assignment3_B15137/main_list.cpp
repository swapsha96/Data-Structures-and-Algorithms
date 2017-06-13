#include <iostream>
#include "list.hpp"

int main() {
	cs202::list<int> *list = new cs202::list<int>();
	list->cons(1);
	list->cons(2);
	list->cons(3);
	// list->remove(2);
	list->print();
	return 0;
}