#include <iostream>
#include "rb_tree.hpp"
#include "rb_node.hpp"

void test_rbt(void)
{
	typedef RBNode<int> node;

	RBTree<int> tree;
	int values[] = {41, 38, 31, 12, 19, 8, 35, 18};
	for (int i = 0; i < 8; i++) {
		if (i%2) {
			tree.kinsert(values[i]);
		} else {
			node* n = new node(values[i], tree.get_sentinel());
			tree.insert(n);
		}
	}

	tree.print();

	std::cout << "min: " << *tree.min() << std::endl;
	std::cout << "max: " << *tree.max() << std::endl; 

	node *bar = tree.search(19);
	std::cout << "search 19: " << *bar << std::endl;

	std::cout << std::endl << "Successors:" << std::endl;
	for (int i = 0; i < 8; i++) {
		node *n = tree.search(values[i]);
		if (tree.successor(n) != tree.get_sentinel())
			std::cout << values[i] << ": " << *tree.successor(n) << std::endl;
		else
			std::cout << values[i] << " dont have successor" << std::endl;
	}

	std::cout << std::endl << "Predecessors:" << std::endl;
	for (int i = 0; i < 8; i++) {
		node *n = tree.search(values[i]);
		if (tree.predecessor(n) != tree.get_sentinel())
			std::cout << values[i] << ": " << *tree.predecessor(n) << std::endl;
		else
			std::cout << values[i] << " dont have predecessor" << std::endl;
	}

	std::cout << std::endl;
    tree.print();
}