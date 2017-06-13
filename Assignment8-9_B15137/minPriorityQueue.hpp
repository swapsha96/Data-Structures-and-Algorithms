#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1

using namespace std;

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
 		LinearList<T> _heap;
 		int _heapSize;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos);

 		// return the parent of an element
 		inline int parent(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);

 		inline void exchange(T& a, T& b);



 	public:
 		// default constructor
 		MinPriorityQueue();

 		// construct a heap from the elements of a seqLinearList
 		MinPriorityQueue(LinearList<T>& v);

 		//copy constructor
 		MinPriorityQueue(MinPriorityQueue<T>& q);

 		// insert a value to the heap
 		void insert(const T& a);

 		// get the minimum element from the heap
 		inline T& minimum();

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int heap_size();

 		// build a heap from elements of a seqLinearList container 
 		void build_heap(const LinearList<T>& v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);

 		void heap_decrease_key(const size_t& pos,const T& a);
 	};

 	template<class T>
 	MinPriorityQueue<T>::MinPriorityQueue(){

 		_heap.resize(13);
 		_heapSize = 0;
 	}

 	template<class T>
	MinPriorityQueue<T>::MinPriorityQueue(LinearList<T>& v){
		_heapSize = v.size();
		
		for(int i = 0; i < _heapSize; i++)
			_heap.push_back(v.at(i));

		for(int i = _heapSize/2; i >= 0 ; i--)
			heapify(i);
	}

 	template<class T>
	MinPriorityQueue<T>::MinPriorityQueue(MinPriorityQueue<T>& q){
		_heapSize = q._heapSize;
		
		for(int i = 0; i <= _heapSize; i++)
			_heap.push_back(q._heap.at(i));
	}

	template<class T>
	int MinPriorityQueue<T>::heap_size(){
		return _heapSize;
	}

	template<class T>
	bool MinPriorityQueue<T>::empty(){
		if(_heapSize)
			return false;
		else
			return true;
	}

	template<class T>
	int MinPriorityQueue<T>::parent(const size_t& pos){
		
		return (pos - 1)/2;
	}

	template<class T>
	int MinPriorityQueue<T>::left_child(const size_t& pos){
		
		return 2*pos + 1;
	}

	template<class T>
	int MinPriorityQueue<T>::right_child(const size_t& pos){
		
		return 2*(pos + 1);
	}

	template<class T>
	T& MinPriorityQueue<T>::minimum(){
		if(!empty())
			return _heap[0];
		else
			throw "Queue is empty";
	}

	template<class T>
	T MinPriorityQueue<T>::extract_min(){
		if(!empty()){
			T min = _heap[0];
			_heap[0] = _heap[_heapSize - 1];
			_heapSize--;

			if(!empty())
				heapify(0);

			return min;
		}
		else
			throw "Queue is empty";
	}

	template<class T>
	void MinPriorityQueue<T>::build_heap(const LinearList<T>& v){
		_heapSize = v.size();

		for(int i = 0; i < _heapSize; i++)
			_heap[i] = v[i];

		for(int i = _heapSize; i >= 0; i--)
			heapify(i);
	}

	template<class T>
	void MinPriorityQueue<T>::insert(const T& a){

		_heap[_heapSize] = a;
		heap_decrease_key(_heapSize);
		_heapSize++;
	}

	template<class T>
	void MinPriorityQueue<T>::heap_decrease_key(const size_t& pos){

		int par = parent(pos);
		int i = pos;

		while(i > 0 && _heap[i] < _heap[par]){
			
			exchange(_heap[i], _heap[par]);

			i = par;
			par = parent(i); 
		}
	}

	template<class T>
	void MinPriorityQueue<T>::heap_decrease_key(const size_t& pos,const T& a){

		_heap[pos] = a;
		int par = parent(pos);
		int i = pos;

		while(i > 0 && _heap[i] < _heap[par]){
			
			exchange(_heap[i], _heap[par]);

			i = par;
			par = parent(i); 
		}
	}

	template<class T>
	void MinPriorityQueue<T>::heapify(const size_t& pos){

		int l = left_child(pos), r = right_child(pos);
		int smallest;

		if(l < _heapSize && _heap[l] < _heap[pos])
			smallest = l;
		else
			smallest = pos;

		if(r < _heapSize && _heap[r] < _heap[smallest])
			smallest = r;

		if(smallest != pos){
			exchange(_heap[pos], _heap[smallest]);
			heapify(smallest);
		}
	}

	template<class T>
	void MinPriorityQueue<T>::exchange(T& a, T& b){

		 T tmp;
		 tmp = b;
		 b = a;
		 a = tmp; 
	}
}	
#endif 