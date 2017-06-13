#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high);	//TC: n^2 SC: 1
		void bubbleSort(LinearList<Item>& A, int low, int high);
	 	void rankSort(LinearList<Item>& A, int low, int high);
        void selectionSort(LinearList<Item>& A, int low, int high);

//		void mergeSort(LinearList& A, int low, int high);
//            	void quickSort(LinearList& A, int low, int high);
};

template<class Item> void swap(Item *a, Item *b) {
	Item t = *a;
	*a = *b;
	*b = t;
}

template<class Item> void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high){
	int i, j, n;
	Item key;
	n = high+1;
	low++;
	for(i = low; i < n; i++) {
		key = A[i+1];
		j = i-1;
		while(j >= low-1 && A[j+1] > key) {
			A[j+2] = A[j+1];
			j = j-1;
		}
		A[j+2] = key;
	}
};

template<class Item> void Sort<Item>::bubbleSort(LinearList<Item>& A, int low, int high){
	int i, j, n;
	for(i = low; i <= high; i++)
		for(j = low; j < high+low-i; j++)
			if(A[j+1] > A[j+2])
				swap(&A[j+1], &A[j+2]);
};

template<class Item> void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high){
	int i, j, n;
	n = high+1;
	int R[n];
	Item U[n];
	for(int j = 1; j <= n; j++)
		R[j] = 1;
	for(int j = 2; j <= n; j++)
		for(int i = 1; i <= j-1; i++)
			if(A[i] <= A[j])
				R[j]++;
			else
				R[i]++;
	for(int j = 1; j <= n; j++)
		U[R[j]] = A[j];
	for(int j = 1; j <= n; j++)
		A[j] = U[j];
};

template<class Item> void Sort<Item>::selectionSort(LinearList<Item>& A, int low, int high){
	int i, j, n, min_i;
	n = high+1;
	for(i = 0; i < n-1; i++) {
		min_i = i;
		for(j = i+1; j < n; j++)
			if(A[min_i+1] > A[j+1])
				min_i = j;
		swap(&A[min_i+1], &A[i+1]);
	}
};