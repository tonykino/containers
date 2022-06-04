#include <iostream>
#include "test.hpp"

#include "rb_tree.hpp"
#include "rb_node.hpp"

int main(void)
{
	typedef RBNode<int> node;

	RBTree<int> tree;
	int values[] = {41, 38, 31, 12, 19, 8, 35};
	for (int i = 0; i < 7; i++) {
		tree.kinsert(values[i]);
	}

	tree.print();

	std::cout << "min: " << *tree.min() << std::endl;
	std::cout << "max: " << *tree.max() << std::endl; 

	node *bar = tree.search(19);
	std::cout << "search 19: " << *bar << std::endl;

	std::cout << std::endl << "Successors:" << std::endl;
	for (int i = 0; i < 7; i++) {
		node *n = tree.search(values[i]);
		if (tree.successor(n) != tree.get_sentinel())
			std::cout << values[i] << ": " << *tree.successor(n) << std::endl;
		else
			std::cout << values[i] << " dont have successor" << std::endl;
	}

	std::cout << std::endl << "Predecessors:" << std::endl;
	for (int i = 0; i < 7; i++) {
		node *n = tree.search(values[i]);
		if (tree.predecessor(n) != tree.get_sentinel())
			std::cout << values[i] << ": " << *tree.predecessor(n) << std::endl;
		else
			std::cout << values[i] << " dont have predecessor" << std::endl;
	}

	std::cout << std::endl;

	return 0;
}