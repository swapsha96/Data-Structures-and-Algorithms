/* 
 * stack.hpp
 * 
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 * 
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

namespace cs202 {
    template<typename T>class stack {
        private:
            list<T> *head;
        public:
            /*
             * Constructs a new stack.
             */
            stack();
            /*
             * Pushes t to on the top of the stack.
             */
            void push(const T& t);
            /*
             * Returns the element at the top of the stack.
             * Also removes the top element from the stack.
             */
            T pop();
            /*
             * Returns the element at the top of the stack.
             * Does not remove the top element.
             */
            T top();
            /*
             * Returns the number of elements currently in the stack.
             */
            int size();
            /*
             * Returns a boolean indicating whether the stack is empty or not.
             */
            inline bool empty();
            /*
             * Prints stack from top to bottom.
             */
            void print();
            /*
             * Destructor
             * Fress the memory occupied by the stack elements.
             */
            ~stack();
    };

    template<class T> stack<T>::stack() {
        this->head = new list<T>();
    }

    template<class T> void stack<T>::push(const T &t) {
        head->cons(t);
    }

    template<class T> T stack<T>::pop() {
        if(head->length() == 0) {
            return 0;
        }
        else {
            T value = head->front();
            head->remove(value);
            return value;
        }
    }

    template<class T> T stack<T>::top() {
        if(head->length() == 0)
            return 0;
        else
            return head->front();
    }

    template<class T> int stack<T>::size() {
        return head->length();
    }

    template<class T> bool stack<T>::empty() {
        return (head->length() == 0) ? true : false;
    }

    template<class T> stack<T>::~stack() {
        delete head;
    }

    template<class T> void stack<T>::print() {
        head->print();
    }
}

#endif