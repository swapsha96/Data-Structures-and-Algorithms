/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
#include "Dictionary.hpp"

namespace cs202
{
template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{
    /*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
private:
    int MAX;
    cs202::list<Key, Value> **hash;
public:
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap() {
        MAX = 10;
        hash = new cs202::list<Key, Value> *[MAX];
        for(int i = 0; i < MAX; i++)
            hash[i] = new cs202::list<Key, Value>();
    };
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num) {
        MAX = num;
        hash = new cs202::list<Key, Value> *[num];
        for(int i = 0; i < num; i++)
            hash[i] = new cs202::list<Key, Value>();
    };
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht) {
        MAX = 10;
        hash = new cs202::list<Key, Value> *[MAX];
        hash = ht->getList();
    };
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap() {
        delete hash;
    };
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);

    Key hashFunc(Key key) {
        return key % MAX;
    }
    /*
     * Function : has
     * Returns true if the dictionay contains the key
     * false otherwise. It is search operation
     */
    virtual bool has(const Key& key) {
        Key hash_key = hashFunc(key);
        cs202::list<Key, Value> *list = hash[hash_key];
        return list->find(key) != -1 ? true : false;
    };
    /*
     * Function : remove
     * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
     * Does nothing otherwise.
     */
    virtual void remove(const Key& key) {
        Key hash_key = hashFunc(key);
        cs202::list<Key, Value> *list = hash[hash_key];
        list->remove(key);
    };
    /*
     * Function : get
     * Returns the value associated with the given key.
     * Raises an exception if the key does'nt exist in the dictionary.
     */
    Value get(const Key& key) {
        Key hash_key = hashFunc(key);
        cs202::list<Key, Value> *list = hash[hash_key];
        return list->find(key); 
    };
    /*
     * Function : put
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
    void put(const Key& key, const Value& value){
        Key hash_key = hashFunc(key);
        cs202::list<Key, Value> *list = hash[hash_key];
        list->append(key, value);
    }
    /*
     * Function : print
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
    void print(){
        for(int i = 0; i < MAX; i++) {
            hash[i]->print();
        }
    }
    /*
     * Function : getList
     * Returns complete arrays of linked list
     */
    list<Key, Value> ** getList(){
        return this->hash;
    }
};
}

#endif /* CHAINEDMAP_HPP_ */