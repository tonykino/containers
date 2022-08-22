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

	std::cout << "container is empty? " << foo.empty() << std::endl;
	std::cout << "size: " << foo.size() << std::endl;
	foo._tree.insert(node1);
	foo._tree.insert(node3);
	foo._tree.insert(node5);
	foo._tree.print();

	std::cout << "container is empty? " << foo.empty() << std::endl;
	std::cout << "size: " << foo.size() << std::endl;

	// ft::map<const int, std::string>::iterator it = foo.begin();
	// ft::map<const int, std::string>::reverse_iterator it2 = foo.rbegin();

	// Test iterator and reverse iterator
	std::cout << "begin : " << (*foo.begin()).second << std::endl;
	std::cout << "end   : " << (*foo.end()).second << std::endl;
	std::cout << "rend  : " << (*foo.rend()).second << std::endl;
	std::cout << "rbegin: " << (*foo.rbegin()).second << std::endl;

	std::cout << "find(3) : " << (*foo.find(3)).first << std::endl;
	std::cout << "find(5) : " << (*foo.find(5)).first << std::endl;
	std::cout << "find(1) : " << (*foo.find(1)).first << std::endl;
	std::cout << "find(8) : " << (*foo.find(8)).first << std::endl;

	std::cout << "count(3) : " << foo.count(3) << std::endl;
	std::cout << "count(8) : " << foo.count(8) << std::endl;
	
	std::cout << "lower_bound(3) : " << (*foo.lower_bound(3)).first << std::endl;
	std::cout << "lower_bound(4) : " << (*foo.lower_bound(4)).first << std::endl;
	std::cout << "lower_bound(5) : " << (*foo.lower_bound(5)).first << std::endl;

	std::cout << "upper_bound(3) : " << (*foo.upper_bound(3)).first << std::endl;
	std::cout << "upper_bound(4) : " << (*foo.upper_bound(4)).first << std::endl;
	std::cout << "upper_bound(5) : " << (*foo.upper_bound(5)).first << std::endl;

	// std::pair<int, int> test = std::make_pair(3, 5);
	// std::cout << test.first << std::endl;

	return 0;
}