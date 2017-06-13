#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1
#include <iostream>
using namespace std;

template <class Key, class Value>
class BinaryNode
{
public:
	Key key;
	Value val;
  int color;
	BinaryNode<Key,Value> * root,* left,* right,* parent;
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode() {
    key = -1;
    val = -1;
    root = NULL;
    left = NULL;
    right = NULL;
    parent = NULL;
    color = 1;
  };
  /*This contructor should assign the key and val from the passed parameters
     */
  BinaryNode(Key key, Value value) {
    this->key = key;
    this->val = value;
    root = NULL;
    left = NULL;
    right = NULL;
    parent = NULL;
    color = 1;
  };
  /*This contructor should assign the key and val from the passed parameters
     */
  BinaryNode(Key key, Value value, BinaryNode<Key,Value> *root, BinaryNode<Key,Value> *parent) {
    this->key = key;
    this->val = value;
    this->root = root;
    left = NULL;
    right = NULL;
    this->parent = parent;
    color = 0;
  };
};

template<class Key, class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */
protected:
	BinaryNode<Key,Value> *root;

public:
  BinaryTree() {
    this->root = NULL;
  }
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
  Value get(const Key& key) {};
  /* Implement remove function that can delete a node in binary tree with given key. 
   */
  virtual void remove(const Key& key) {};
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.  
   */
  virtual bool has(const Key& key) {};	
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */	
  int height(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return 0;
    else {
      int leftHeight = height(node->left);
      int rightHeight = height(node->right);

      return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
  };

  bool isComplete(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return true;
    if(node->left == NULL && node->right == NULL)
      return true;
    if((node->left) && (node->right))
      return (isComplete(node->left) && isComplete(node->right));
    return false;
  };

  int cal_size(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return 0;
    else
      return cal_size(node->left) + 1 + cal_size(node->right);
  };

  virtual void put(const Key& key, const Value& value) {
    if(this->root == NULL) {
      this->root = new BinaryNode<Key, Value>(key, value, NULL, NULL);
      return;
    }
    BinaryNode<Key, Value> *node, *nodeParent;
    nodeParent = NULL;
    node = this->root;
    while(node) {
      nodeParent = node;
      if(node->left == NULL) {
        node->left = new BinaryNode<Key, Value>(key, value, this->root, nodeParent);
        return;
      }
      if(node->left != NULL && node->right == NULL) {
        node->right = new BinaryNode<Key, Value>(key, value, this->root, nodeParent);
        return;
      }
      if(!isComplete(node->left))
        node = node->left;
      else if(isComplete(node->left) && (cal_size(node->left) != cal_size(node->right)))
        node = node->right;
      else
        node = node->left;
    }
  };
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an in order traversal.
   */
  void inOrder(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return;
    else {
      inOrder(node->left);
      cout << node->key << " ";
      inOrder(node->right);
    }
  }
  virtual void print_in_order(){
    cout << "In Order: ";
    inOrder(root);
    cout << endl;
  };
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an pre order traversal.
   */
  void preOrder(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return;
    else {
      cout << node->key << " ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
  virtual void print_pre_order(){
    cout << "Pre Order: ";
    preOrder(root);
    cout << endl;
  };
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in a post order traversal.
   */
  void postOrder(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return;
    else {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->key << " ";
    }
  }
  virtual void print_post_order(){
    cout << "Post Order: ";
    postOrder(root);
    cout << endl;
  };
  /*
   *This method returns the minimum element in the binary tree.
   */
  virtual Key minimum() {};
  /*
   * This method returns the maximum element in the binary tree.
   */
  virtual Key maximum() {};
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
  virtual Key successor(const Key& key) {};
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
  virtual Key predecessor(const Key& key) {};
};

#endif /* ifndef BINARYTREE_HPP */
