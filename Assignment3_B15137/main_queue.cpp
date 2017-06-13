#include <iostream>
#include "queue.hpp"

int main() {
	cs202::queue<int> *queue = new cs202::queue<int>();
	queue->push(1);
	queue->push(2);
	queue->push(3);
	queue->pop();
	queue->print();
	return 0;
}