#include <iostream>
#include <cstdlib>
#include "DoubleHashMap.hpp"

int main() {
	int n, x, key, value;
	cout << "Enter hash table size: ";
	cin >> n;
	cs202::DoubleHashMap<int, int> *map = new cs202::DoubleHashMap<int, int>(n);
	cout << "Enter number of initial inputs: ";
	cin >> x;
	cout << "Enter " << x << " key-value pair(s):" << endl;
	for (int i = 0; i < x; i++){
		cin >> key >> value;
		map->put(key, value);
	}
	map->print();
	while(1) {
		cout << "1. Put" << endl;
		cout << "2. Get" << endl;
		cout << "3. Has" << endl;
		cout << "4. Remove" << endl;
		cout << "Enter you choice: ";
		int input;
		cin >> input;
		switch(input) {
			case 1 : {
				cout << "Enter " << x << " key-value pair: ";
				cin >> key >> value;
				map->put(key, value);
			}
			break;
			case 2 : {
				cout << "Enter " << x << " key: ";
				cin >> key;
				cout << key << ": " << map->get(key) << endl;
			}
			break;
			case 3 : {
				cout << "Enter " << x << " key: ";
				cin >> key;
				cout << key << ": " << map->has(key) << endl;
			}
			break;
			case 4 : {
				cout << "Enter " << x << " key: ";
				cin >> key;
				map->remove(key);
			}
			break;
			default : {
				exit(1);
			}
		}
		map->print();
	}
	// map->put(109, 109);
	// map->put(115, 19);
	// map->put(122, 17);
	// map->put(125, 13);
	// map->put(225, 14);
	// map->put(305, 17);
	// map->put(412, 28);
	// map->put(327, 34);
	// map->put(334, 96);
	// map->put(339, 73);
	// map->put(43, 73);

	// map->remove(109);
	// map->put(405, 73);
	
	return 0;
}