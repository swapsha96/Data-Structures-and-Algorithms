#ifndef SORTING
#define SORTING

#include <iostream>
#include "seqLinearList.hpp"

namespace cs202 {
template<class T>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<T>& A, int low, int high);	//TC: n^2 SC: 1
		void bubbleSort(LinearList<T>& A, int low, int high);
	 	void rankSort(LinearList<T>& A, int low, int high);
        void selectionSort(LinearList<T>& A, int low, int high);
		void mergeSort(LinearList<T>& A, int low, int high);
		void quickSort(LinearList<T>& A, int low, int high);
};

template<class T> void swap(T *a, T *b) {
	T t = *a;
	*a = *b;
	*b = t;
}

template<class T> void Sort<T>::insertionSort(LinearList<T>& A, int low, int high){
	int i, j, n;
	T key;
	n = high+1;
	low++;
	for(i = low; i < n; i++) {
		key = A[i];
		j = i-1;
		while(j >= low-1 && A[j] > key) {
			A[j+1] = A[j];
			j = j-1;
		}
		A[j+1] = key;
	}
};

template<class T> void Sort<T>::bubbleSort(LinearList<T>& A, int low, int high){
	int i, j, n;
	n = high+1;
	for(i = low; i < n-1; i++)
		for(j = low; j < n+low-i-1; j++)
			if(A[j+1] > A[j+2])
				swap(&A[j+1], &A[j+2]);
};

template<class T> void Sort<T>::rankSort(LinearList<T>& A, int low, int high){
	int i, j, n;
	low--;
	high--;
	n = high+1;
	int R[n];
	T U[n];
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

template<class T> void Sort<T>::selectionSort(LinearList<T>& A, int low, int high){
	int i, j, n, min_i;
	n = high;
	for(i = 0; i < n-1; i++) {
		min_i = i;
		for(j = i+1; j < n; j++)
			if(A[min_i+1] > A[j+1])
				min_i = j;
		swap(&A[min_i+1], &A[i+1]);
	}
};

template<class T> void merge(LinearList<T>& A, int low, int middle, int high) {
	int i, j, k;
	int n1 = middle - low + 1;
	int n2 = high - middle;

	T A1[n1];
	T A2[n2];

	for(i = 0; i < n1; i++)
		A1[i+1] = A[low+i+1];
	for(i = 0; i < n2; i++)
		A2[i+1] = A[middle+1+i+1];

	i = 0, j = 0, k = low;
	while(i < n1 && j < n2)
		if(A1[i+1] <= A2[j+1])
			A[k++ +1] = A1[i++ +1];
		else
			A[k++ +1] = A2[j++ +1];

	while(i < n1)
		A[k++ +1] = A1[i++ +1];
	while(j < n2)
		A[k++ +1] = A2[j++ +1];
}

template<class T> void Sort<T>::mergeSort(LinearList<T>& A, int low, int high){
	if(low < high) {
		int middle = low + (high-low)/2;
		mergeSort(A, low, middle);
		mergeSort(A, middle+1, high);
		merge(A, low, middle, high);
	}
};

template<class T> int partition(LinearList<T>& A, int low, int high) {
	T pivot = A[high+1];
	int i = low-1;
	for(int j = low; j < high; j++)
		if(A[j+1] <= pivot) {
			i++;
			swap(&A[i+1], &A[j+1]);
		}
	swap(&A[i+2], &A[high+1]);
	return (i+1);
}

template<class T> void Sort<T>::quickSort(LinearList<T>& A, int low, int high) {
	if(low < high) {
		int pivot = partition(A, low, high);
		quickSort(A, low, pivot-1);
		quickSort(A, pivot+1, high);
	}
}

}

#endif