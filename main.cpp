#include <iostream>
#include <utility>
#include "test.hpp"
#include "map.hpp"
#include "rb_node.hpp"
#include "rb_tree.hpp"

int main(void)
{
	ft::map<const int, std::string> foo;

	std::cout << "container is empty? " << foo.empty() << std::endl;
	std::cout << "size: " << foo.size() << std::endl;
	foo.insert(foo._tree.get_root(), std::make_pair(1, std::string("un")));
	foo.insert(foo._tree.get_root(), std::make_pair(3, std::string("trois")));
	foo.insert(foo._tree.get_root(), std::make_pair(3, std::string("sept")));
	foo.insert(foo._tree.get_root(), std::make_pair(3, std::string("trois")));
	foo.insert(foo._tree.get_root(), std::make_pair(3, std::string("trois")));
	foo.insert(foo._tree.get_root(), std::make_pair(3, std::string("treize")));
	foo.insert(foo._tree.get_root(), std::make_pair(5, std::string("cinq")));
	foo.insert(foo._tree.get_root(), std::make_pair(5, std::string("cinq")));
	foo.insert(foo._tree.get_root(), std::make_pair(5, std::string("quatre")));
	foo.insert(foo._tree.get_root(), std::make_pair(5, std::string("douze")));
	foo.insert(foo._tree.get_root(), std::make_pair(6, std::string("douze")));
	foo[13];
	foo._tree.print();

	std::cout << "container is empty? " << foo.empty() << std::endl;
	std::cout << "size: " << foo.size() << std::endl;

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

	// erase nothing
	foo.erase(12);
	foo._tree.print();

	foo.erase(1);
	foo.erase(foo.find(3));
	foo._tree.print();
	// foo.erase(foo.begin(), foo.end());
	foo.clear();
	foo._tree.print();

	return 0;
}
