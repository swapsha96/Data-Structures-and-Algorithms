/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */

#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_
#include "OpenMap.hpp"

namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
{
private:
    int MAX;
    Key *T;
    Value *val;
public:
    /*
     * Constructor: DoubleHashMap
     * Creates a Double Hash Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap() {
        MAX = 11;
        T = new Key[MAX];
        val = new Value[MAX];
        for(int i = 0; i < MAX; i++)
            T[i] = -1;
        for(int i = 0; i < MAX; i++)
            val[i] = 0;
    };
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num) {
        MAX = num;
        T = new Key[num];
        val = new Value[num];
        for(int i = 0; i < num; i++)
            T[i] = -1;
        for(int i = 0; i < num; i++)
            val[i] = 0;
    };
    /*
     * Constructor: Double Hash Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~DoubleHashMap() {
        delete T;
    };
    /*
     * Function : get
     * Returns the value associated with the given key.
     * Raises an exception if the key does'nt exist in the dictionary.
     */
    Value get(const Key& key) {
        Key i = 0;
        Key j = hashFunc(key);
        Key offset = hashOffset(key);
        while(T[j] != -1 && i < MAX) {
            if(T[j] == key)
                return val[j];
            else {
                j = (j+offset) % MAX;
                i++;
            }
        }
        return 0;
    };
    Key hashFunc(Key key) {
        return key % MAX;
    }
    Key hashOffset(Key key) {
        Key m = 5;
        return m - (key % m);
    }
    /*
     * Function : has
     * Returns true if the dictionay contains the key
     * false otherwise. It is search operation
     */
    virtual bool has(const Key& key) {
        Key i = 0;
        Key j = hashFunc(key);
        Key offset = hashOffset(key);
        while(T[j] != -1 && i < MAX) {
            if(T[j] == key)
                return true;
            else {
                j = (j+offset) % MAX;
                i++;
            }
        }
        return false;
    };
    /*
     * Function : remove
     * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
     * Does nothing otherwise.
     */
    virtual void remove(const Key& key) {
        Key i = 0;
        Key j = hashFunc(key);
        Key offset = hashOffset(key);
        while(T[j] != -1 && i < MAX) {
            if(T[j] == key) {
                T[j] = -1;
                return;
            }
            else {
                j = (j+offset) % MAX;
                i++;
            }
        }
        return;
    };
    /*
     * Function : put
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
    void put(const Key& key, const Value& value){
        Key i = 0;
        Key j = hashFunc(key);
        Key offset = hashOffset(key);
        while(T[j] != -1 && i < MAX) {
            j = (j+offset) % MAX;
            i++;
        }
        if(i == MAX)
            rehash(5);
        T[j] = key;
        val[j] = value;
    }
    /*
     * Function : print
     */
    void print(){
        for(int i = 0; i < MAX; i++)
            if(T[i] != -1)
                cout << val[i] << " ";
            else
                cout << -1 << " ";
        cout << endl;
    }
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
    void rehash(int m) {
        cout << "Rehashing..." << endl;
        Key *tempT;
        Value *tempVal;
        tempT = new Key[MAX];
        tempVal = new Value[MAX];
        for(int i = 0; i < MAX; i++){
            tempT[i] = T[i];
            tempVal[i] = val[i];
        }
        MAX += m;
        T = new Key[MAX+m];
        val = new Value[MAX+m];
        for(int i = 0; i < MAX; i++) {
            T[i] = -1;
            val[i] = -1;
        }
        for(int i = 0; i < (MAX-m); i++)
            this->put(tempT[i], tempVal[i]);
    }
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
    Value& operator[](const int& key) {
        if(this->has() == false)
            this->put(key, 0);
        return this->get(key);
    };
};
}

#endif 