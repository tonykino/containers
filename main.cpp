#include <iostream>
#include "test.hpp"
#include "map.hpp"

int main(void)
{
	ft::map<int, std::string> foo;
	foo._tree.print();
	return 0;
}