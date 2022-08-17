#include <iostream>
#include <utility>
#include "test.hpp"
#include "map.hpp"
#include "rb_node.hpp"
#include "rb_tree.hpp"

int main(void)
{
	ft::map<const int, std::string> foo;
	RBNode<std::pair<const int, std::string> > *node1 = new RBNode<std::pair<const int, std::string> >(std::make_pair(1, std::string("un")), foo._tree.get_sentinel());
	RBNode<std::pair<const int, std::string> > *node3 = new RBNode<std::pair<const int, std::string> >(std::make_pair(3, std::string("trois")), foo._tree.get_sentinel());
	RBNode<std::pair<const int, std::string> > *node5 = new RBNode<std::pair<const int, std::string> >(std::make_pair(5, std::string("cinq")), foo._tree.get_sentinel());
	// RBTree<std::pair<int, int> > foo;
	// std::pair<int, int> test = std::make_pair(3, 5);
	foo._tree.insert(node1);
	foo._tree.print();
	foo._tree.insert(node3);
	foo._tree.print();
	foo._tree.insert(node5);
	foo._tree.print();

	// ft::map<const int, std::string>::iterator it = foo.begin();
	// ft::map<const int, std::string>::reverse_iterator it2 = foo.rbegin();

	// Test iterator and reverse iterator
	std::cout << "begin : " << (*foo.begin()).second << std::endl;
	std::cout << "end   : " << (*foo.end()).second << std::endl;
	std::cout << "rend  : " << (*foo.rend()).second << std::endl;
	std::cout << "rbegin: " << (*foo.rbegin()).second << std::endl;

	
	// std::pair<int, int> test = std::make_pair(3, 5);
	// std::cout << test.first << std::endl;

	return 0;
}