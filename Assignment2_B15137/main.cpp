// Driver Program for testing `seqLinearList` class
// Author:
// Roll Number:
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sorting.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
	int n, x, m;
	double time;
	fstream file;
	file.open("asc_2.txt", ios::out|ios::app);
	//Create and add LinearList elements
	// cout << "Enter the max length of LinearList: ";
	cin >> n;
	// cout << "Enter the number of elements to add: ";
	// cin >> m;
	m = n;
	file << n;
	cs202::LinearList<int> linearList = cs202::LinearList<int>(n);
	for(int i = 0; i < m; i++) {
		// cout << "Enter element at position " << i+1 << ": ";
		cin >> x;
		linearList.insert(x, i);
	}
	// cout << "------------------------------------------" << endl;
	
	cs202::Sort<int> sort;
	for(int p = 1; p <argc; p++) {
		int option;
		// cout << "LinearList: ";
		// linearList.display(); //display all elements

		// cout << "0. Exit" << endl;
		// cout << "1. Insertion sorting" << endl;
		// cout << "2. Bubble sorting" << endl;
		// cout << "3. Rank sorting" << endl;
		// cout << "4. Selection sorting" << endl;
		// cout << "5. Merge sorting" << endl;
		// cout << "6. Quick sorting" << endl;
		// cout << "Enter your choice of operation: ";
		// cin >> option;
		// cout << endl;
		option = atoi(argv[p]);
		switch(option) {
			case 0: {
				exit(EXIT_SUCCESS);
			} break;
			case 1: {
				//Insertion sort
				cs202::LinearList<int> insertionList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.insertionSort(insertionList, 1, m);
				clock_t end = clock();
				// cout << "LinearList sorted using Insertion sorting: ";
				// insertionList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
			case 2: {
				// Bubble sort
				cs202::LinearList<int> bubbleList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.bubbleSort(bubbleList, 0, m-1);
				clock_t end = clock();
				// cout << "LinearList sorted using Bubble sorting: ";
				// bubbleList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
			case 3: {
				// Rank sort
				cs202::LinearList<int> rankList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.rankSort(rankList, 1, m);
				clock_t end = clock();
				// cout << "LinearList sorted using Rank sorting: ";
				// rankList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
			case 4: {
				//Selection sort
				cs202::LinearList<int> selectionList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.selectionSort(selectionList, 1, m);
				clock_t end = clock();
				// cout << "LinearList sorted using Selection sorting: ";
				// selectionList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
			case 5: {
				//Merge sort
				cs202::LinearList<int> mergeList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.mergeSort(mergeList, 0, m-1);
				clock_t end = clock();
				// cout << "LinearList sorted using Merge sorting: ";
				// mergeList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
			case 6: {
				//Quick sort
				cs202::LinearList<int> quickList = cs202::LinearList<int>(linearList);
				clock_t start = clock();
				sort.quickSort(quickList, 0, m-1);
				clock_t end = clock();
				// cout << "LinearList sorted using Quick sorting: ";
				// quickList.display();
				time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
				cout << "Running time: " << time << " millisec" << endl;
				file << "\t" << time;
			} break;
		}
		// cout << "------------------------------------------" << endl;
	}
	file << "\n";
	return 0;
}