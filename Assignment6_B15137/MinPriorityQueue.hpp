// Purpose: 
// Author: Swapnil Sharma
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqLinearList.hpp"

namespace cs202{
 	
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.


 		// Primary container used in MinPriorityQueue
 		LinearList<T> heap;
 		int heap_size;

 		// swap function
 		void swap(const int &a, const int &b) {
 			T temp = heap[a];
 			heap[a] = heap[b];
 			heap[b] = temp;
 		}

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos) {
 			int i = pos, smallest;
 			int left = left_child(i);
 			int right = right_child(i);
 			if(left <= heap_size && heap[left] < heap[i])
 				smallest = left;
 			else
 				smallest = i;

 			if(right <= heap_size && heap[right] < heap[smallest])
 				smallest = right;

 			if(smallest != i) {
 				swap(i, smallest);
 				heapify(smallest);
 			}
 		};

 		// return the parent of an element
 		inline int parent(const size_t& pos) {
 			return pos/2;
 		};

 		// return the left child of an element
 		inline int left_child(const size_t& pos) {
 			return (2*pos <= heap_size) ? 2*pos : -1;
 		};

 		// return the right child of an element
 		inline int right_child(const size_t& pos) {
 			return ((2*pos+1) <= heap_size) ? (2*pos+1) : -1;
 		};

 	public:
 		// default constructor
 		MinPriorityQueue() {
 			heap_size = 0;
 			heap = LinearList<T>();
 		};

 		// construct a heap from the elements of a LinearList
 		MinPriorityQueue(const LinearList<T>& v) {
 			heap_size = v.sizel();
 			heap = LinearList<T>(v);
 		};

 		// insert a value to the heap
 		void insert(const T& a) {
 			heap_size++;
 			// heap[heap_size] = -1;
 			heap_decrease_key(heap_size, a);
 		};

 		// get the minimum element from the heap
 		inline T minimum() {
 			return heap[1];
 		};

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min() {
 			T min = this->minimum();

 			heap[1] = heap[heap_size];
 			heap_size--;
 			heapify(1);

 			return min;
 		};

 		// return the heap size
 		inline int heapSize() {
 			return heap_size;
 		};

 		// build a heap from elements of a LinearList container 
 		void build_heap(const LinearList<T>& v) {
 			heap = LinearList<T>(v);
 			heap_size = heap.sizel();
 			for(int i = heap_size; i >= 1; i--)
 				heapify(i);
 		};

 		// check if MinPriorityQueue is empty
 		inline bool empty() {
 			return (heap_size == 0) ? true : false;
 		};

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos, const T& key) {
 			int i = pos;
 			heap[i] = key;
 			while(i > 1 && heap[parent(i)] > heap[i]) {
 				swap(i, parent(i));
 				i = parent(i);
 			}
 		};

 		void print() {
 			std::cout << "Heap: ";
 			for(int i = 1; i <= heap_size; i++)
 				std::cout << heap[i] << " ";
 			std::cout << "\n";
 		}
 	};
}
 	
#endif 