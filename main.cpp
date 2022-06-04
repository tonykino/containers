#include <iostream>
#include "test.hpp"

#include "rb_tree.hpp"
#include "rb_node.hpp"

int main(void)
{
	RBTree<int> tree;
	RBNode<int> foo1 = RBNode<int>(41);
	RBNode<int> foo2 = RBNode<int>(38);
	RBNode<int> foo3 = RBNode<int>(31);
	RBNode<int> foo4 = RBNode<int>(12);
	RBNode<int> foo5 = RBNode<int>(19);
	RBNode<int> foo6 = RBNode<int>(8);
	RBNode<int> foo7 = RBNode<int>(35);


	tree.insert(&foo1);
	tree.insert(&foo2);
	tree.insert(&foo3);
	tree.insert(&foo4);
	tree.insert(&foo5);
	tree.insert(&foo6);
	tree.insert(&foo7);

	tree.print();
	return 0;
}