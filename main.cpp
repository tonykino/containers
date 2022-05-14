#include <iostream>
#include <vector>
#include <stack>
#include "Stack.tpp"



int main(void)
{


    /*{
        // TEST VECTOR
        std::vector<int> data;
        data.push_back(1);
        data.push_back(2);
        data.push_back(3);

        for (std::vector<int>::iterator it = data.begin(); it < data.end(); it++)
            std::cout << *it << std::endl;
    }*/

    {
        // TEST STD::STACK
        std::cout << "   --- STD::STACK --- " << std::endl;
        std::stack<int> c1;
        for (int i = 0; i < 5; i++) {
            c1.push((i+1)*2);
            std::cout << "size: " << c1.size() << " "
                      << "top: "  << c1.top()  << std::endl;
        }

		std::stack<int> c2(c1);

		std::cout << "Comparaison tests:" << std::endl;
		std::cout << "c1 == c2 " << (c1 == c2) << std::endl;
		std::cout << "c1 != c2 " << (c1 != c2) << std::endl;
		std::cout << "c1 > c2 " << (c1 > c2) << std::endl;
		std::cout << "c1 >= c2 " << (c1 >= c2) << std::endl;
		std::cout << "c1 < c2 " << (c1 < c2) << std::endl;
		std::cout << "c1 <= c2 " << (c1 <= c2) << std::endl;

		std::cout << "C1: " << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "size: " << c1.size() << " "
                      << "top: "  << c1.top()  << std::endl;
            c1.pop();
        }

		std::cout << "C2: " << std::endl;
		for (int i = 0; i < 5; i++) {
            std::cout << "size: " << c2.size() << " "
                      << "top: "  << c2.top()  << std::endl;
            c2.pop();
        }

    }


    {
        // TEST FT::STACK
        std::cout << "   --- FT::STACK --- " << std::endl;
        ft::stack<int> c1;
        for (int i = 0; i < 5; i++) {
            c1.push((i+1)*2);
            std::cout << "size: " << c1.size() << " "
                      << "top: "  << c1.top()  << std::endl;
        }

		ft::stack<int> c2(c1);

		std::cout << "Comparaison tests:" << std::endl;
		std::cout << "c1 == c2 " << (c1 == c2) << std::endl;
		std::cout << "c1 != c2 " << (c1 != c2) << std::endl;
		std::cout << "c1 > c2 " << (c1 > c2) << std::endl;
		std::cout << "c1 >= c2 " << (c1 >= c2) << std::endl;
		std::cout << "c1 < c2 " << (c1 < c2) << std::endl;
		std::cout << "c1 <= c2 " << (c1 <= c2) << std::endl;

		std::cout << "C1: " << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "size: " << c1.size() << " "
                      << "top: "  << c1.top()  << std::endl;
            c1.pop();
        }

		std::cout << "C2: " << std::endl;
		for (int i = 0; i < 5; i++) {
            std::cout << "size: " << c2.size() << " "
                      << "top: "  << c2.top()  << std::endl;
            c2.pop();
        }
    }

	return 0;
}