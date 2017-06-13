#include <iostream>
#include "MinPriorityQueue.hpp"
using namespace cs202;

class Interrupt {
public:
	int id, burstTime, delay, priorityValue;
	
	inline bool operator<(Interrupt &a) {
		return priorityValue < a.priorityValue;
	}
	
	inline bool operator>(Interrupt &a) {
		return priorityValue > a.priorityValue;
	}
};

int main() {
	MinPriorityQueue<Interrupt> queue;

	int n, x;
	std::cout << "Enter number of interrupts: ";
	std::cin >> n;
	int counter = 0;
	Interrupt cpu;
	cpu.id = -1;
	cpu.delay = 1000;
	cpu.burstTime = 1000;

	for(int i = 0; i < n; i++) {
		Interrupt current;
		std::cin >> current.id >> current.burstTime >> current.delay >> current.priorityValue;
		while(current.delay) {
			Interrupt top = queue.extract_min();
			int min = (top.burstTime < current.delay) ? top.burstTime : current.delay;
			top.burstTime -= min;
			current.delay -= min;
			counter += min;

			if(top.burstTime == 0)
				std::cout << "Device #" << top.id << " has been completed at " << counter << " ms.\n";
			else {
				std::cout << "Device #" << top.id << " still needs " << top.burstTime << " to finish at " << counter << " ms.\n";
				queue.insert(top);
			}
		}
		queue.insert(current);
	}

	return 0;
}