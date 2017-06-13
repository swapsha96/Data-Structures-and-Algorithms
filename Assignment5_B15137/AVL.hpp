#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"
template <class Key,class Value>
class AVL : public BSTree<Key, Value> {
  /*
   * Inherit as much functionality as possible from the BSTree class.
   * Then provide custom AVL Tree functionality on top of that.
   * The AVL Tree should make use of as many BST functions as possible.
   * Override only those methods which are extremely necessary.
   */
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   *
   * The signature of these functions are not provided in order to provide you
   * some flexibility in how you implement the internals of your AVL Tree. But
   * make sure these functions are there.
   */
private:
  BinaryNode<Key, Value> *root;
public:
  AVL() {
    root = NULL;
  };
  
  //In Order Trnsversal
  void inOrder(BinaryNode<Key, Value> *node) {
    if(node == NULL)
      return;
    else {
      inOrder(node->left);
      cout << node->key << " ";
      inOrder(node->right);
    }
  }
  void print_in_order(){
    cout << "In Order: ";
    inOrder(root);
    cout << endl;
  };
}

#endif /* ifndef AVL_HPP */