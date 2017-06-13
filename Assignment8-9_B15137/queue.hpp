#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "list.hpp"

namespace cs202
{
    template <class T>
    class queue
    {
        private:
            list<T> _queue;

        public:
            /*
             * Constructs a new queue.
             */
            queue();
            /*
             * Pushes t to at the back of the queue.
             */
            void push(const T& t);
            /*
             * Returns the element at the front of the queue.
             * Also removes the front element from the queue.
             */
            T pop();
            /*
             * Returns the element at the front of the queue.
             * Does not remove the front element.
             */
            T front();
            /*
             * Returns the number of elements currently in the queue.
             */
            inline int size();
            /*
             * Returns a boolean indicating whether the queue is empty or not.
             */
            inline bool empty();

            void display();
            /*
             * Destructor
             * Fress the memory occupied by the queue elements.
             */
            ~queue();
    };


    template<class T>
    queue<T>::queue(){

    }

    template<class T>
    void queue<T>::push(const T& t){
        _queue.append(t);
    }

    template<class T>
    T queue<T>::pop(){
        T front = _queue.front();
        _queue.remove(front);
        return front;
    }

    template<class T>
    T queue<T>::front(){
        return _queue.front();
    }


    template<class T>
    inline int queue<T>::size(){
        return _queue.length();
    }    

    template<class T>
    inline bool queue<T>::empty(){
        return _queue.empty();
    }

    template<class T>
    void queue<T>::display(){
        _queue.display();
    }

    template<class T>
    queue<T>::~queue(){
        while(!empty())
            pop();
    }    
}
#endif