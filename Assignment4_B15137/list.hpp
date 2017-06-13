/*
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 */

#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
using namespace std;
    

namespace cs202 {
    template<class K, class V> class listNode {
        public:
            K key;
            V value;
            listNode<K, V> *next;
    };

    template<class K, class V> class list {
        private:
            listNode<K, V> *head;
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
            list(const list<K, V> & x);
            /*
             * Destructor.
             * Frees all the memory acquired by the list.
             */
            ~list();
            /*
             * adds value at the end of the list.
             */
            void append(const K& input1, const V& input2);
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
            void cons(const K& input1, const V& input2);
            /*
             * Removes the first occurence of the key from list.
             */
            void remove(const K & x);
            /*
             * Appends the given list x at the end of the current list.
             */
            void append(list<K, V>& x);
            /*
             * Prints the linked list.
             */
            void print();
            /*
             * Returns if key exist.
             */
            V find(const K &key);
    };

    template<class K, class V> list<K, V>::list() {
        this->head = 0;
        this->len = 0;
    }

    template<class K, class V> list<K, V>::list(const list<K, V> & x) {
        // copy constructor
        this->head = x.head;
        this->len = x.len;
    }

    template<class K, class V> list<K, V>::~list() {
        listNode<K, V> *node = head;
        while(head) {
            node = head;
            head = head->next;
            delete node;
        }
    }

    template<class K, class V> void list<K, V>::append(const K& input1, const V& input2) {
        listNode<K, V> *node = head;
        if(len > 0) {
            listNode<K, V> *temp = new listNode<K, V>();
            temp->next = 0;
            temp->key = input1;
            temp->value = input2;
            while(node->next != 0){
                node = node->next;
            }
            node->next = temp;
        }
        else {
            this->head = new listNode<K, V>();
            this->head->key = input1;
            this->head->value = input2;
        }
        len++;
    }

    template<class K, class V> int list<K, V>::length() {
        // returns length of the list
        return this->len;
    }

    template<class K, class V> bool list<K, V>::empty() {
        // returns whether list is empty or not
        return this->len == 0;
    }

    template<class K, class V> void list<K, V>::cons(const K& input1, const V& input2) {
        if(len > 0) {
            listNode<K, V> *temp = new listNode<K, V>();
            temp->key = input1;
            temp->value = input2;
            temp->next = head;
            head = temp;
        }
        else {
            this->head = new listNode<K, V>();
            this->head->key = input1;
            this->head->value = input2;
        }
        len++;
    }

    template<class K, class V> void list<K, V>::remove(const K & x) {
        listNode<K, V> *node = head->next;
        listNode<K, V> *current = head;
        while(node != 0) {
            if(node->key == x) {
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
        if(head->key == x) {
            node = head->next;
            delete head;
            head = node;
            len--;
        }
    }

    template<class K, class V> void list<K, V>::append(list<K, V>& x) {
        this->head = x->head;
        this->len += x->len;
    }

    template<class K, class V> void list<K, V>::print() {
        listNode<K, V> *node = head;
        while(node) {
            cout << node->key << ": " << node->value << " ";
            node = node->next;
        }
        cout << endl;
    };

    template<class K, class V> V list<K, V>::find(const K &key) {
        listNode<K, V> *node = head;
        while(node) {
            if(node->key != key)
                node = node->next;
            else
                break;
        }
        if(!node)
            return -1;
        else
            return node->value;
    };
}

#endif