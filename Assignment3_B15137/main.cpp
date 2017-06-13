#include <iostream>
#include "queue.hpp"

int main() {
	int n, i;
	cs202::queue<int> *queue = new cs202::queue<int>();
	cin >> n >> i;
	for(int j = 1; j <= n; j++) {
		queue->push(j);
	}
	while(queue->size() != 1) {
		for(int  j = 0; j < i-1; j++) {
			int front = queue->pop();
			queue->push(front);
		}
		queue->pop();
	}
	cout << "Safe position: " << queue->pop() << endl;
	return 0;
}