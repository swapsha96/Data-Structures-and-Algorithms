#ifndef SEQLINEARLIST
#define SEQLINEARLIST

#include <iostream>
#include <string.h>
#define DEFAULT_VECTOR_SIZE 5

namespace cs202{
	template<typename T>
    class LinearList{
      private:
        T* buffer;
        unsigned int size;
        unsigned int capacity;
      public:
        // Default Constructor
        // Creates a zero sized LinearList
        LinearList();

        // Constructor with size as input
        LinearList(const int& isize);

        //copy constructor
        LinearList(const LinearList &b);                   

        // Constuctor with size and default value as input
        LinearList(const int& isize, const T& ival);    

        // Default Destructor
        ~LinearList();                                  

        // Accessing an element of the LinearList using operator
        inline T& operator[](const int& i);         

        // Return the element in the list at position k
        inline T& at(const int& k);         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const T& item);              

        // Returns true if LinearList is empty
        bool empty();                               

        // Returns the size of the LinearList
        unsigned int sizel();                                 

        // Returns the capacity of the LinearList
        unsigned int capacityl();                                 

        // Fills all the elements with a default value
        void fill(const T& item);                   

        // Resizes the LinearList
        void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const T& item);

        // Remove all occurences of an item in the list
        void erase(const T& item);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

        // Insert item at position k
        void insert(const T& item, const int& k);

        void display();

        // Iterator class for LinearList
        // This should be used to traverse the LinearList
        // See std::vector<T>::iterator for more understanding
        // on how iterators work
        /*class iterator{                             
          private:
            T* elem_;
          public:
            iterator();
            iterator(T* ptr);
            ~iterator();
            T& operator*();
            void operator=(T *ptr);
            void operator=(iterator iter);
            void operator++();
            void operator--();
            bool operator!=(T* ptr);
            bool operator==(T* ptr);
            bool operator!=(iterator iter);
            bool operator==(iterator iter);
            iterator operator+(int i);
            iterator operator-(int i);
        };
        iterator begin();                       
        iterator end();*/
	};



	template <typename T> LinearList <T> :: LinearList() {

	}

	template <typename T> LinearList <T> :: LinearList(const LinearList &b)	{
				capacity = b.capacity;
				size = b.size;
				buffer = new T[size];
				for(int i=0 ; i<capacity ; i++) {
					buffer[i] = b.buffer[i];
				}
			}

	template <typename T> LinearList <T> ::LinearList(const int& MaxListSize) {
		capacity = MaxListSize;
		size = 0;
		buffer = new T [MaxListSize];
		for(int i=0 ; i<MaxListSize ; i++)
			buffer[i] = 0;
	}

	template <typename T> LinearList <T> ::LinearList(const int& MaxListSize,const T& val) {
		capacity = MaxListSize;
		size = 0;
		buffer = new T [MaxListSize];
		for(int i=0 ; i<MaxListSize ; i++)
			buffer[i] = val;

	}

	template <typename T>
	LinearList<T>::~LinearList() {
		//delete(element);
	}

	template <typename T> bool LinearList <T> ::empty() {
		if(size==0)
			return true;
		else 
			return false;
	}

	template <typename T> unsigned int LinearList <T> ::sizel() {
		return size;

	}

	template <typename T> unsigned int LinearList <T> ::capacityl() {
		return capacity;
	}

	template <typename T>inline T& LinearList <T> ::at(const int& k) {
		if(k <= capacity && k <= size)
			return buffer[k];
		else
			return size;
	}

	template <typename T>inline T& LinearList <T> ::operator[](const int& i) {
		int j = i-1;
		return buffer[j];
	}

	template <typename T> void LinearList <T> ::push_back(const T& item) {
		if(size<capacity) {
			buffer[size] = item;
			size++;
		}
		if(size == capacity) {
			resize(capacity + DEFAULT_VECTOR_SIZE);
			buffer[size] = item;
			size++;
		}
	}

	template<typename T> void LinearList<T> :: fill(const T& item) {
		for(int i = 0 ; i<capacity ; i++)
			buffer[i] = item;
	}

	template<typename T> void LinearList<T> ::resize(const int& n) {
		int index;
		T *temp;
		temp = new T[n];
		if(n>=size)
			index = size;
		else {	
			index = n;
			capacity = n;
			size = n;	
		}
		for(int i=0 ; i<index ; i++)
			temp[i] = buffer[i];
		delete[] buffer;
		buffer = temp;
	}

	template <typename T> int LinearList <T> ::find(const T& item) {
		int i;
		for(i = 0; i<size; i++)
			if(buffer[i] == item)
				return i;
		return size;
	}

	template <typename T> void LinearList <T> ::erase_pos(const int& k) {

		int i,e,x;
		e = k;
		if(e<size && k>=0) {	
			x = buffer[e];
			for(i = e ; i<size ; i++)
				buffer[i] = buffer[i+1];
			size--;
		}
	}

	template <typename T> void LinearList <T> ::erase(const T& x) {
		int e;
		int flag = 1;
		while(flag == 1) {	
			flag = 0;
			for(int j = 0 ; j<size ; j++)
				if(buffer[j] == x) {	
					e=j;
					flag = 1;	
				} 
			if(flag == 1) {	
				if(e == size-1)
					size--;
				else {		
					for(int i = e ; i < size ; i++)
						buffer[i] = buffer[i+1];
					size--;
				}
			}
		}
	}

	template <typename T> void LinearList <T> :: insert(const T& k , const int& x) {
		int pos = x;
		if(size == capacity)
			resize(capacity + DEFAULT_VECTOR_SIZE);
		if(pos == size) {	
			buffer[pos] = k;
			size++;
		}
		else {
			for(int i = size ; i>pos ; i--)
				buffer[i] = buffer[i-1];
			buffer[pos] = k;
			size++;
		}
	}

	template <typename T> void LinearList <T> ::display() {
		for(int i=0 ; i<size ; i++)
			std::cout<< buffer[i]<<" ";
		std::cout << "\n";
	}
}
#endif
