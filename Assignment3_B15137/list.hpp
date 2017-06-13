/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * 
 */

#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
using namespace std;
    

namespace cs202 {
    template<class T> class listNode {
        public:
            T data;
            listNode<T> *next;
    };

    template<class T> class list {
        private:
            listNode<T> *head;
            int len;
        public:
            /*
             * Primary contructor.
             * Should construct an empty list.
             * len of the created list should be zero.
             */
            list();
            /*
             * Seondary constructor.
             * Creates a new list which is a copy of the provided list.
             */
            list(const list<T> & x);
            /*
             * Destructor.
             * Frees all the memory acquired by the list.
             */
            ~list();
            /*
             * adds value at the end of the list.
             */
            void append(const T& value);
            /*
             * Returns the length of the list.
             */
            inline int length();
            /*
             * Returns a boolean indicating whether the list is empty.
             */
            inline bool empty();
            /*
             * Adds a value to the front of the list.
             */
            void cons(const T& value);
            /*
             * Removes the first occurence of the value from list.
             */
            void remove(const T & x);
            /*
             * Appends the given list x at the end of the current list.
             */
            void append(list<T>& x);
            /*
             * Prints the linked list.
             */
            void print();
            /*
             * Returns first element.
             */
            T front();
            /*
             * Returns last element.
             */
            T end();
    };

    template<class T> list<T>::list() {
        this->head = 0;
        this->len = 0;
    }

    template<class T> list<T>::list(const list<T> & x) {
        // copy constructor
        this->head = x.head;
        this->len = x.len;
    }

    template<class T> list<T>::~list() {
        listNode<T> *node = head;
        while(head) {
            node = head;
            head = head->next;
            delete node;
        }
    }

    template<class T> void list<T>::append(const T& value) {
        listNode<T> *node = head;
        if(len > 0) {
            listNode<T> *temp = new listNode<T>();
            temp->next = 0;
            temp->data = value;
            while(node->next != 0){
                node = node->next;
            }
            node->next = temp;
        }
        else {
            this->head = new listNode<T>();
            this->head->data = value;
        }
        len++;
    }

    template<class T> int list<T>::length() {
        // returns length of the list
        return this->len;
    }

    template<class T> bool list<T>::empty() {
        // returns whether list is empty or not
        return this->len == 0 ? true : false;
    }

    template<class T> void list<T>::cons(const T& value) {
        if(len > 0) {
            listNode<T> *temp = new listNode<T>();
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        else {
            this->head = new listNode<T>();
            this->head->data = value;
        }
        len++;
    }

    template<class T> void list<T>::remove(const T & x) {
        listNode<T> *node = head->next;
        listNode<T> *current = head;
        while(node != 0) {
            if(node->data == x) {
                current->next = node->next;
                len--;
                delete node;
                return;
            }
            else{
                node = node->next;
                current = current->next;
            }
        }
        if(head->data == x) {
            node = head->next;
            delete head;
            head = node;
            len--;
        }
    }

    template<class T> void list<T>::append(list<T>& x) {
        this->head = x->head;
        this->len += x->len;
    }

    template<class T> void list<T>::print() {
        listNode<T> *node = head;
        while(node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    };

    template<class T> T list<T>::front() {
        return head->data;
    };

    template<class T> T list<T>::end() {
        listNode<T> *node = head;
        while(node->next != 0) {
            node = node->next;
        }
        return node->data;
    };
}

#endif