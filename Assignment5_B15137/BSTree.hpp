#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"

template <class Key, class Value>
class BSTree : public BinaryTree<Key, Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
private:
	BinaryNode<Key, Value> *root;
 public:
 	BSTree() {
 		this->root = NULL;
 	}
  /*
   * This method returns the current height of the binary search tree.
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
	virtual int getHeight() {
		return height(this->root);
	};
  /*
   * This method returns the total number of elements in the binary search tree.
   */
	int cal_size(BinaryNode<Key, Value> *node) {
		if(node == NULL)
			return 0;
		else
			return cal_size(node->left) + 1 + cal_size(node->right);
	};

	virtual int size() {
		return cal_size(this->root);
	};
  /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
	virtual void print() {};

	// Insertion without recurrence
	void put(const Key& key, const Value& value) {
		if(this->root == NULL)
			this->root = new BinaryNode<Key, Value>(key, value, NULL, NULL);
		else {
			BinaryNode<Key, Value> *parentNode, *node;
			parentNode = NULL;
			node = this->root;
			while(node != NULL) {
				parentNode = node;
				if(node->key < key)
					node = node->right;
				else
					node = node->left;
			}
			if(parentNode->key < key)
				parentNode->right = new BinaryNode<Key, Value>(key, value, this->root, parentNode);
			else
				parentNode->left = new BinaryNode<Key, Value>(key, value, this->root, parentNode);
		}
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

	// Pre Order Transversal
	void preOrder(BinaryNode<Key, Value> *node) {
		if(node == NULL)
			return;
		else {
			cout << node->key << " ";
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
		if(node == NULL)
			return;
		else {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << " ";
		}
	}
	void print_post_order(){
		cout << "Post Order: ";
		postOrder(root);
		cout << endl;
	};

	//Minimum key
	Key minimum() {
		BinaryNode<Key, Value> *node;
		node = this->root;
		while(node->left != NULL)
			node = node->left;
		return node->key;
	};

	//Minimum key
	Key minimum(BinaryNode<Key, Value> *node) {
		while(node->left != NULL)
			node = node->left;
		return node->key;
	};

	//Maximum key
	Key maximum() {
		BinaryNode<Key, Value> *node;
		node = this->root;
		while(node->right != NULL)
			node = node->right;
		return node->key;
	};

	//Maximum key
	Key maximum(BinaryNode<Key, Value> *node) {
		while(node->right != NULL)
			node = node->right;
		return node->key;
	};

	//In order predecessor
	Key predecessor(const Key& key) {
		if(this->root == NULL)
			return -1;

		BinaryNode<Key, Value> *node, *parentNode;
		node = this->root;
		parentNode = NULL;
		while(node != NULL) {
			parentNode = node;
			if(node->key == key) {
				if(node->left != NULL)
					return this->maximum(node->left);
				else {
					node = node->parent;
					while(node->left != NULL &&node->left->key == key  && node->parent != NULL)
						node = node->parent;
					if(node->key < key)
						return node->key;
					else
						return -1;
				}
			}
			else if(node->key < key)
				node = node->right;
			else
				node = node->left;
		}
		return -1;
	};

	//In order successor
	Key successor(const Key& key) {
		if(this->root == NULL)
			return -1;

		BinaryNode<Key, Value> *node, *parentNode;
		node = this->root;
		parentNode = NULL;
		while(node != NULL) {
			parentNode = node;
			if(node->key == key) {
				if(node->right != NULL)
					return this->minimum(node->right);
				else {
					node = node->parent;
					while(node->right != NULL && node->right->key == key  && node->parent != NULL)
						node = node->parent;
					if(node->key > key)
						return node->key;
					else
						return -1;
				}
			}
			else if(node->key < key)
				node = node->right;
			else
				node = node->left;
		}
		return -1;
	};

	bool has(const Key& key) {
		BinaryNode<Key, Value> *node;
		node = root;
		while(node) {
			if(node->key == key)
				return true;
			else if(node->key < key)
				node = node->right;
			else
				node = node->left;
		}
		return false;
	};

	Value get(const Key& key) {
		BinaryNode<Key, Value> *node;
		node = root;
		while(node) {
			if(node->key == key)
				return node->val;
			else if(node->key < key)
				node = node->right;
			else
				node = node->left;
		}
		return -1;
	};

	void remove(const Key& key) {
		if(root == NULL)
			return;
		else {
			BinaryNode<Key, Value> *parentNode, *node;
			parentNode = NULL;
			node = root;
			while(node != NULL) {
				parentNode = node;
				if(node->key == key) {
					parentNode = node->parent;
					if(node->left == NULL && node->right == NULL) {
						if(node->parent->left == node)
							node->parent->left = NULL;
						else
							node->parent->right = NULL;
						node = NULL;
						return;
					}
					if(node->left == NULL && node->right != NULL) {
						if(node->parent->left == node)
							node->parent->left = node->right;
						else
							node->parent->right = node->right;
						node->right->parent = node->parent;
						node = NULL;
						return;
					}
					if(node->left != NULL && node->right == NULL) {
						if(node->parent->left == node)
							node->parent->left = node->left;
						else
							node->parent->right = node->left;
						node->left->parent = node->parent;
						node = NULL;
						return;
					}
					if(node->left != NULL && node->right != NULL) {
						BinaryNode<Key, Value> *tempLeft, *tempRight, *temp;
						tempRight = node->right;
						tempLeft = node->left;
						
						temp = tempLeft;
						while(temp->right != NULL)
							temp = temp->right;
						temp->right = tempRight;

						if(node->parent->left == node)
							node->parent->left = tempLeft;
						else
							node->parent->right = tempLeft;

						tempLeft->parent = node->parent;
						return;
					}
					return;
				}
				if(node->key < key)
					node = node->right;
				else
					node = node->left;
			}
			return;
		}
	};
};

#endif /* ifndef BSTREE_HPP */