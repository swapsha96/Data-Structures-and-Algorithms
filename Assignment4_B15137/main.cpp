#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <cstdlib>
#include "ChainedMap.hpp"
#include "DoubleHashMap.hpp"

void readChainedMap(int m, int n, cs202::ChainedMap<int, int> *main, cs202::ChainedMap<int, int> *cache, int *counter, int loc) {
	int pos = loc/4;
	if(pos >= m)
		return;
	if(counter[pos] == -1){
		cache->put(pos, main->get(pos));
		counter[pos]++;
	}
	else{
		if(cache->has(pos) == false) {
			int isFull = 1;
			for(int i = 0; i < n; i++)
				if(counter[i] == -1)
					isFull = 0;
			if(isFull == 1){
				int x = 0;
				for(int i = 0; i < n; i++)
					if(counter[i] > counter[x])
						x = i;
				cache->remove(x);
				cache->put(pos, main->get(pos));
				pos = x;
			}
			else
				cache->put(pos, main->get(pos));
		}
		counter[pos] = 0;
	}
	for(int i = 0; i < n; i++)
		if(i != pos && counter[i] != -1)
			counter[i]++;
	cout << "Main:\n";
	main->print();
	cout << "Cache:\n";
	cache->print();
	cout << "Counter:";
	for(int i = 0; i < n; i++)
		cout << counter[i] << " ";
	cout << endl;
}

void readOpenMap(int m, int n, cs202::OpenMap<int, int> *main, cs202::OpenMap<int, int> *cache, int *counter, int loc) {
	int pos = loc/4;
	if(pos >= m)
		return;
	if(counter[pos] == -1){
		cache->put(pos, main->get(pos));
		counter[pos]++;
	}
	else{
		if(cache->has(pos) == false) {
			int isFull = 1;
			for(int i = 0; i < n; i++)
				if(counter[i] == -1)
					isFull = 0;
			if(isFull == 1){
				int x = 0;
				for(int i = 0; i < n; i++)
					if(counter[i] > counter[x])
						x = i;
				cache->remove(x);
				cache->put(pos, main->get(pos));
				pos = x;
			}
			else
				cache->put(pos, main->get(pos));
		}
		counter[pos] = 0;
	}
	for(int i = 0; i < n; i++)
		if(i != pos && counter[i] != -1)
			counter[i]++;
	cout << "Main:\t";
	main->print();
	cout << "Cache:\t";
	cache->print();
	cout << "Counter:";
	for(int i = 0; i < n; i++)
		cout << counter[i] << " ";
	cout << endl;
}

void readDoubleHashMap(int m, int n, cs202::DoubleHashMap<int, int> *main, cs202::DoubleHashMap<int, int> *cache, int *counter, int loc) {
	int pos = loc/4;
	if(pos >= m)
		return;
	if(counter[pos] == -1){
		cache->put(pos, main->get(pos));
		counter[pos]++;
	}
	else{
		if(cache->has(pos) == false) {
			int isFull = 1;
			for(int i = 0; i < n; i++)
				if(counter[i] == -1)
					isFull = 0;
			if(isFull == 1){
				int x = 0;
				for(int i = 0; i < n; i++)
					if(counter[i] > counter[x])
						x = i;
				cache->remove(x);
				cache->put(pos, main->get(pos));
				pos = x;
			}
			else
				cache->put(pos, main->get(pos));
		}
		counter[pos] = 0;
	}
	for(int i = 0; i < n; i++)
		if(i != pos && counter[i] != -1)
			counter[i]++;
	cout << "Main:\t";
	main->print();
	cout << "Cache:\t";
	cache->print();
	cout << "Counter:";
	for(int i = 0; i < n; i++)
		cout << counter[i] << " ";
	cout << endl;
}

int main() {
	int n = 4, m = 8, t;
	// cout << "Enter Main and Cache memory size (to the power of 2): ";
	// cin >> m >> n;
	while(1) {
		int input = 1;
		cout << "1. Chained hashing." << endl;
		cout << "2. Linear probing." << endl;
		cout << "3. Double probing." << endl;
		cout << "Enter your choice: ";
		cin >> input;
		switch(input) {
			case 1 : {
				//Initializations
				cs202::ChainedMap<int, int> *main = new cs202::ChainedMap<int, int>(m);
				cs202::ChainedMap<int, int> *cache = new cs202::ChainedMap<int, int>(n);
				int *counter = new int[n];
				for(int i = 0; i < n; i++)
					counter[i] = -1;
				for(int i = 0; i < m; i++)
					main->put(i, i);
				//Read
				while(1) {
					cout << "Enter main memory address: ";
					cin >> t;
					if(t >= m*4)
						break;
					readChainedMap(m, n, main, cache, counter, t);
				}
			}
			break;
			case 2 : {
				//Initializations
				cs202::OpenMap<int, int> *main = new cs202::OpenMap<int, int>(m);
				cs202::OpenMap<int, int> *cache = new cs202::OpenMap<int, int>(n);
				int *counter = new int[n];
				for(int i = 0; i < n; i++)
					counter[i] = -1;
				for(int i = 0; i < m; i++)
					main->put(i, i);
				//Read
				while(1) {
					cout << "Enter main memory address: ";
					cin >> t;
					if(t >= m*4)
						break;
					readOpenMap(m, n, main, cache, counter, t);
				}
			}
			break;
			case 3 : {
				//Initializations
				cs202::DoubleHashMap<int, int> *main = new cs202::DoubleHashMap<int, int>(m);
				cs202::DoubleHashMap<int, int> *cache = new cs202::DoubleHashMap<int, int>(n);
				int *counter = new int[n];
				for(int i = 0; i < n; i++)
					counter[i] = -1;
				for(int i = 0; i < m; i++)
					main->put(i, i);
				//Read
				while(1) {
					cout << "Enter main memory address: ";
					cin >> t;
					if(t >= m*4)
						break;
					readDoubleHashMap(m, n, main, cache, counter, t);
				}
			}
			break;
			default : {
				exit(1);
			}
		}
	}

	// read(m, n, main, cache, counter, 3);
	// read(m, n, main, cache, counter, 7);
	// read(m, n, main, cache, counter, 11);
	// read(m, n, main, cache, counter, 2);
	// read(m, n, main, cache, counter, 8);
	// read(m, n, main, cache, counter, 14);
	// read(m, n, main, cache, counter, 16);
	// read(m, n, main, cache, counter, 23);
	// read(m, n, main, cache, counter, 25);
	return 0;
}