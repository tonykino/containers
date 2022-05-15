#include <iostream>
#include <vector>
#include <stack>
#include "Stack.hpp"
#include "Vector.hpp"

template<typename T>
void print_vector(T & v) {
	std::cout << "s:" << v.size() << " c:" << v.capacity() << " | ";
	for (typename T::iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void)
{

	// {
	// 	// TEST STD::VECTOR.INSERT
	// 	std::cout << "   --- STD::VECTOR.INSERT SEGFAULT---" << std::endl;

	// 	std::vector<int> v;

	// 	v.insert(v.begin(), 3);

	// 	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
    //     	std::cout << *it << " ";
	// 	std::cout << std::endl;

	// 	try // Insert at a wrong position == segfault, no exception thrown
	// 	{
	// 		v.insert(v.end() + 3, 4);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cout << e.what() << std::endl;
	// 	}

	// 	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
    //     	std::cout << *it << " ";
	// 	std::cout << std::endl;
		
	// }

	{
		// TEST STD::VECTOR.INSERT
		std::cout << "   --- STD::VECTOR.INSERT ---" << std::endl;

		std::vector<int> v;
		v.insert(v.begin(), 7, 3);
		print_vector(v);
		v.insert(v.begin() + 3, 4);
		print_vector(v);
		v.insert(v.begin() + 4, 3, 42);
		print_vector(v);
	}


	{
		// TEST STD::VECTOR.INSERT
		std::cout << "   --- FT::VECTOR.INSERT ---" << std::endl;

		ft::vector<int> v;
		v.insert(v.begin(), 7, 3);
		print_vector(v);
		v.insert(v.begin() + 3, 4);
		print_vector(v);
		v.insert(v.begin() + 4, 3, 42);
		print_vector(v);
	}


    {
        // TEST STD::VECTOR
		std::cout << std::endl << "   --- STD::VECTOR.PUSH_BACK --- " << std::endl;

        std::vector<int> v1;
		print_vector(v1);
        v1.push_back(1);
		print_vector(v1);
        v1.push_back(3);
		print_vector(v1);
        v1.push_back(5);
		print_vector(v1);
        v1.push_back(7);
        v1.push_back(9);
		print_vector(v1);
        v1.push_back(2);
        v1.push_back(4);
        v1.push_back(6);
		print_vector(v1);
        v1.push_back(8);
        v1.push_back(10);
		print_vector(v1);

        // std::vector<int> v2(v1);
		// print_vector(v2);
        // v2.push_back(11);
		// print_vector(v2);

        std::vector<int> v3(10, 3);
		print_vector(v3);
    }


    {
        // TEST FT::VECTOR
		std::cout << std::endl << "   --- FT::VECTOR.PUSH_BACK --- " << std::endl;

        ft::vector<int> v1;
		print_vector(v1);
        v1.push_back(1);
		print_vector(v1);
        v1.push_back(3);
		print_vector(v1);
        v1.push_back(5);
		print_vector(v1);
        v1.push_back(7);
        v1.push_back(9);
		print_vector(v1);
        v1.push_back(2);
        v1.push_back(4);
        v1.push_back(6);
		print_vector(v1);
        v1.push_back(8);
        v1.push_back(10);
		print_vector(v1);

        // ft::vector<int> v2(v1);
		// print_vector(v2);
        // v2.push_back(11);
		// print_vector(v2);

        ft::vector<int> v3(10, 3);
		print_vector(v3);

    }

    // {
    //     // TEST STD::STACK
    //     std::cout << "   --- STD::STACK --- " << std::endl;
    //     std::stack<int> c1;
    //     for (int i = 0; i < 5; i++) {
    //         c1.push((i+1)*2);
    //         std::cout << "size: " << c1.size() << " "
    //                   << "top: "  << c1.top()  << std::endl;
    //     }

	// 	std::stack<int> c2(c1);

	// 	std::cout << "Comparaison tests:" << std::endl;
	// 	std::cout << "c1 == c2 " << (c1 == c2) << std::endl;
	// 	std::cout << "c1 != c2 " << (c1 != c2) << std::endl;
	// 	std::cout << "c1 > c2 " << (c1 > c2) << std::endl;
	// 	std::cout << "c1 >= c2 " << (c1 >= c2) << std::endl;
	// 	std::cout << "c1 < c2 " << (c1 < c2) << std::endl;
	// 	std::cout << "c1 <= c2 " << (c1 <= c2) << std::endl;

	// 	std::cout << "C1: " << std::endl;
    //     for (int i = 0; i < 5; i++) {
    //         std::cout << "size: " << c1.size() << " "
    //                   << "top: "  << c1.top()  << std::endl;
    //         c1.pop();
    //     }

	// 	std::cout << "C2: " << std::endl;
	// 	for (int i = 0; i < 5; i++) {
    //         std::cout << "size: " << c2.size() << " "
    //                   << "top: "  << c2.top()  << std::endl;
    //         c2.pop();
    //     }

    // }


    // {
    //     // TEST FT::STACK
    //     std::cout << "   --- FT::STACK --- " << std::endl;
    //     ft::stack<int> c1;
    //     for (int i = 0; i < 5; i++) {
    //         c1.push((i+1)*2);
    //         std::cout << "size: " << c1.size() << " "
    //                   << "top: "  << c1.top()  << std::endl;
    //     }

	// 	ft::stack<int> c2(c1);

	// 	std::cout << "Comparaison tests:" << std::endl;
	// 	std::cout << "c1 == c2 " << (c1 == c2) << std::endl;
	// 	std::cout << "c1 != c2 " << (c1 != c2) << std::endl;
	// 	std::cout << "c1 > c2 " << (c1 > c2) << std::endl;
	// 	std::cout << "c1 >= c2 " << (c1 >= c2) << std::endl;
	// 	std::cout << "c1 < c2 " << (c1 < c2) << std::endl;
	// 	std::cout << "c1 <= c2 " << (c1 <= c2) << std::endl;

	// 	std::cout << "C1: " << std::endl;
    //     for (int i = 0; i < 5; i++) {
    //         std::cout << "size: " << c1.size() << " "
    //                   << "top: "  << c1.top()  << std::endl;
    //         c1.pop();
    //     }

	// 	std::cout << "C2: " << std::endl;
	// 	for (int i = 0; i < 5; i++) {
    //         std::cout << "size: " << c2.size() << " "
    //                   << "top: "  << c2.top()  << std::endl;
    //         c2.pop();
    //     }
    // }

	return 0;
}