#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int main() {
	BinaryTree<int, int> *tree = new BinaryTree<int, int>();
	tree->put(3, 3);
	tree->put(2, 2);
	tree->put(1, 1);
	tree->put(5, 5);
	tree->put(4, 4);
	tree->put(6, 6);
	tree->put(7, 7);

	tree->print_in_order();
	tree->print_pre_order();
	tree->print_post_order();

	// cout << "Height: " << tree->getHeight() << endl;
	// cout << "Size: " << tree->size() << endl;

	// cout << "Minimum key: " << tree->minimum() << endl;
	// cout << "Maximum key: " << tree->maximum() << endl;

	// for(int i = 1; i <= 6; i++)
	// 	cout << "Predecessor key of " << i << ": " << tree->predecessor(i) << endl;
	// for(int i = 1; i <= 6; i++)
	// 	cout << "Successor key of " << i << ": " << tree->successor(1) << endl;

	// for(int i = 4; i <= 9; i++)
	// 	cout << "Has " << i << ": " << tree->has(i) << endl;
	// for(int i = 4; i <= 9; i++)
	// 	cout << "Value of key " << i << ": " << tree->get(i) << endl;

	// tree->remove(2);
	// tree->print_in_order();
	// tree->remove(1);
	// tree->print_in_order();
	// tree->remove(5);
	// tree->print_in_order();
	
	return 0;
}