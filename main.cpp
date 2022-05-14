#include <iostream>
#include <vector>
#include <stack>
#include "Stack.hpp"
#include "Vector.hpp"



int main(void)
{

    {
        // TEST STD::VECTOR
		std::cout << std::endl << "   --- STD::VECTOR --- " << std::endl;

        std::vector<int> v1;
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(1);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(2);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(3);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(4);
        v1.push_back(5);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(6);
        v1.push_back(7);
        v1.push_back(8);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(9);
        v1.push_back(10);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;

        // std::vector<int> v2(v1);
		// std::cout << "v2: size:" << v2.size() << " capacity:" << v2.capacity() << " max_size:" << v2.max_size() << std::endl;
        // v2.push_back(11);
		// std::cout << "v2: size:" << v2.size() << " capacity:" << v2.capacity() << " max_size:" << v2.max_size() << std::endl;



        // std::vector<int> v3(10, 3);
		// std::cout << "v3: size:" << v3.size() << " capacity:" << v3.capacity() << " max_size:" << v3.max_size() << std::endl;


        // for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
        //     std::cout << *it << std::endl;
    }


    {
        // TEST FT::VECTOR
		std::cout << std::endl << "   --- FT::VECTOR --- " << std::endl;

        ft::vector<int> v1;
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(1);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(2);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(3);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(4);
        v1.push_back(5);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(6);
        v1.push_back(7);
        v1.push_back(8);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;
        v1.push_back(9);
        v1.push_back(10);
		std::cout << "v1: size:" << v1.size() << " capacity:" << v1.capacity() << " max_size:" << v1.max_size() << std::endl;

        // std::vector<int> v2(v1);
		// std::cout << "v2: size:" << v2.size() << " capacity:" << v2.capacity() << " max_size:" << v2.max_size() << std::endl;
        // v2.push_back(11);
		// std::cout << "v2: size:" << v2.size() << " capacity:" << v2.capacity() << " max_size:" << v2.max_size() << std::endl;



        // std::vector<int> v3(10, 3);
		// std::cout << "v3: size:" << v3.size() << " capacity:" << v3.capacity() << " max_size:" << v3.max_size() << std::endl;


        // for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
        //     std::cout << *it << std::endl;
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