#include <iostream>
#include "MinPriorityQueue.hpp"
using namespace cs202;

int main() {
	LinearList<int> list;
	MinPriorityQueue<int> queue;

	int n, x;
	std::cout << "Enter number of inputs: ";
	std::cin >> n;

	for(int i = 0; i < n; i++) {
		std::cin >> x;
		list.push_back(x);
	}
	queue.build_heap(list);
	queue.print();

	std::cout << "Minimum: " << queue.minimum() << "\n";
	std::cout << "Extract Minimum: " << queue.extract_min() << "\n";
	queue.print();

	return 0;
}