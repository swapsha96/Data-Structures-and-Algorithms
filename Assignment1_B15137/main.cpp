#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.hpp"
using namespace std;

int main() {
	int n, x, m;
	//Create and add LinearList elements
	cout << "Enter the max length of LinearList: ";
	cin >> n;
	cout << "Enter the number of elements to add: ";
	cin >> m;
	LinearList<int> linearList = LinearList<int>(n);
	for(int i = 0; i < m; i++) {
		cout << "Enter element at position " << i+1 << ": ";
		cin >> x;
		linearList.insert(i+1,x);
	}
	cout << "------------------------------------------" << endl;
	Sort<int> sort;
	while(1) {
		int option;
		cout << "LinearList: ";
		//Print all elements
		linearList.print();
		cout << "1. Insertion sorting" << endl;
		cout << "2. Bubble sorting" << endl;
		cout << "3. Rank sorting" << endl;
		cout << "4. Selection sorting" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice of operations: ";
		cin >> option;
		switch(option) {
			case 1: {
				//Insertion sort
				LinearList<int> insertionList = LinearList<int>(linearList);
				clock_t start = clock();
				sort.insertionSort(insertionList, 1, m);
				clock_t end = clock();
				cout << "LinearList sorted using Insertion sorting: ";
				insertionList.print();
				double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
			} break;
			case 2: {
				// Bubble sort
				LinearList<int> bubbleList = LinearList<int>(linearList);
				clock_t start = clock();
				sort.bubbleSort(bubbleList, 1, m);
				clock_t end = clock();
				cout << "LinearList sorted using Bubble sorting: ";
				bubbleList.print();
				double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
			} break;
			case 3: {
				// Rank sort
				LinearList<int> rankList = LinearList<int>(linearList);
				clock_t start = clock();
				sort.rankSort(rankList, 2, m);
				clock_t end = clock();
				cout << "LinearList sorted using Rank sorting: ";
				rankList.print();
				double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
			} break;
			case 4: {
				//Selection sort
				LinearList<int> selectionList = LinearList<int>(linearList);
				clock_t start = clock();
				sort.selectionSort(selectionList, 1, m);
				clock_t end = clock();
				cout << "LinearList sorted using Selection sorting: ";
				selectionList.print();
				double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
			} break;
			case 5: {
				exit(EXIT_SUCCESS);
			} break;
		}
		cout << "------------------------------------------" << endl;
	}
}