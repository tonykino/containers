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
		node *n = new node(values[i]);
		tree.insert(n);
	}

	std::cout << "RBTree :" << std::endl;
	tree.print();

	std::cout << std::endl;
	std::cout << "min: " << *tree.min() << std::endl;
	std::cout << "max: " << *tree.max() << std::endl; 

	node *bar = tree.search(19);
	std::cout << "search 19: " << *bar << std::endl;

	std::cout << std::endl << "Successors:" << std::endl;
	for (int i = 0; i < 7; i++) {
		node *n = tree.search(values[i]);
		if (n->successor())
			std::cout << values[i] << ": " << *n->successor() << std::endl;
		else
			std::cout << values[i] << " dont have successor" << std::endl;
	}

	std::cout << std::endl << "Predecessors:" << std::endl;
	for (int i = 0; i < 7; i++) {
		node *n = tree.search(values[i]);
		if (n->predecessor())
			std::cout << values[i] << ": " << *n->predecessor() << std::endl;
		else
			std::cout << values[i] << " dont have predecessor" << std::endl;
	}

	std::cout << std::endl;

	return 0;
}