#include <iostream>
#include "ChainedMap.hpp"

int main() {
	cs202::ChainedMap<int, int> *map = new cs202::ChainedMap<int, int>();
	map->put(0, 19);
	map->put(1, 19);
	map->put(2, 17);
	map->put(3, 13);
	map->put(4, 14);
	map->put(5, 17);
	map->put(6, 28);
	map->put(7, 34);
	map->put(8, 96);
	map->put(9, 73);

	// map->print();
	map->remove(8);

	cout << "Value of key 7: " << map->get(7) << endl;

	cout << "Check if map has key 21: ";
	map->has(21) ? cout << "true" << endl : cout << "false" << endl;

	map->print();
	
	return 0;
}