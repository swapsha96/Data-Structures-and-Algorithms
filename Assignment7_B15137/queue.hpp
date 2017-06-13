/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of queues
 * 
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

namespace cs202 {
template <class T> class queue {
    private:
            list<T> *head;
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
        /*
         * Prints queue from left to right.
         */
        void print();
        /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue();
    };

    template <class T> queue<T>::queue() {
        this->head = new list<T>();
    }

    template <class T> void queue<T>::push(const T& t) {
        head->append(t);
    }

    template <class T> T queue<T>::pop() {
        T value = head->front();
        head->remove(value);
        return value;
    }

    template <class T> T queue<T>::front() {
        return head->front();
    }

    template <class T> int queue<T>::size() {
        return head->length();
    }

    template <class T> bool queue<T>::empty() {
        return head->length() == 0 ? true : false;
    }

    template <class T> void queue<T>::print() {
        head->print();
    }

    template <class T> queue<T>::~queue() {
        delete head;
    }
}
#endif