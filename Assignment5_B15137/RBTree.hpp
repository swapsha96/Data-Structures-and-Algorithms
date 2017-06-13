#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */
enum Color {RED = 1, BLACK = 0};

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	void left_rotate(BinaryNode<Key, Value>* &x) {
		BinaryNode<Key, Value> *y;
		y = x->right;
		x->right = y->left;
		if(y->left != this->nil) 
			y->left->parent = x;
		y->parent = x->parent;
		if(x->parent == this->nil)
			this->root = y;
		else if(x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	};


	void right_rotate(BinaryNode<Key, Value>* &x) {
		BinaryNode<Key, Value> *y;
		y = x->left;
		x->left = y->right;
		if(y->right != this->nil) 
			y->right->parent = x;
		y->parent = x->parent;
		if(x->parent == this->nil)
			this->root = y;
		else if(x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	};

	void insertRBFixup(BinaryNode<Key, Value>* &z) {
		while(z->parent->color == RED) {
			if(z->parent == z->parent->parent->left) {
				BinaryNode<Key, Value> *y;
				y = z->parent->parent->right;
				if(y->color == RED) {
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else if(z == z->parent->right) {
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
			else {
				BinaryNode<Key, Value> *y;
				y = z->parent->parent->left;
				if(y->color == RED) {
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else if(z == z->parent->left) {
					z = z->parent;
					right_rotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
		this->root->color = BLACK;
	};

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBTransplant(BinaryNode<Key, Value>* &u, BinaryNode<Key, Value>* &v) {
		if(u->parent == this->nil)
			this->root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	};
	void deleteRBFixup(BinaryNode<Key, Value>* &z) {
		y = z;
	};
private:
	BinaryNode<Key, Value> *root, *nil;
public:
	RBTree() {
		this->nil = new BinaryNode<Key, Value> ();
		this->nil->color = BLACK;
		this->root = this->nil;
		this->root->parent = this->nil;
		this->root->left = this->nil;
		this->root->right = this->nil;
		this->root->root = this->nil;
	};
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */
	int blackHeight(BinaryNode<Key, Value> *child) {};	
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
	void rb_insert(const Key& key, const Value& value) {
		BinaryNode<Key, Value> *x, *y, *z;
		z = new BinaryNode<Key, Value>();
		z->key = key;
		z->val = value;
		z->left = this->nil;
		z->right = this->nil;
		z->root = this->root;
		z->parent = this->nil;
		z->color = RED;

		y = this->nil;
		x = this->root;
		while(x != this->nil) {
			y = x;
			if(z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if(y == this->nil)
			this->root = z;
		else if(z->key < y->key) 
			y->left = z;
		else
			y->right = z;

		z->left = this->nil;
		z->right = this->nil;
		z->color = RED;
		insertRBFixup(z);
	};

	//In Order Trnsversal
	void inOrder(BinaryNode<Key, Value> *node) {
		if(node == this->nil)
			return;
		else {
			inOrder(node->left);
			cout << node->key << "(" << node->color << ") ";
			inOrder(node->right);
		}
	}
	void print_in_order(){
		cout << "In Order: ";
		inOrder(root);
		cout << endl;
	};

	// Pre Order Transversal
	void preOrder(BinaryNode<Key, Value> *node) {
		if(node == this->nil)
			return;
		else {
			cout << node->key << "(" << node->color << ") ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void print_pre_order(){
		cout << "Pre Order: ";
		preOrder(root);
		cout << endl;
	};

	// Post Order Transversal
	void postOrder(BinaryNode<Key, Value> *node) {
		if(node == this->nil)
			return;
		else {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << "(" << node->color << ") ";
		}
	}
	void print_post_order(){
		cout << "Post Order: ";
		postOrder(root);
		cout << endl;
	};
};
#endif /* ifndef RBTree_HPP_ */