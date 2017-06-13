#include <iostream>
#include "RBTree.hpp"
using namespace std;

int main() {
	RBTree<int, int> *tree = new RBTree<int, int>();
	tree->rb_insert(1, 1);
	tree->rb_insert(2, 2);
	tree->rb_insert(3, 3);
	// tree->rb_insert(5, 5);
	// tree->rb_insert(4, 4);
	// tree->rb_insert(6, 6);
	tree->print_in_order();
	tree->print_pre_order();
	tree->print_post_order();
	
	return 0;
}