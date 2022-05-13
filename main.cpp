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
        std::stack<int> data;
        for (int i = 0; i < 5; i++) {
            data.push((i+1)*2);
            std::cout << "size: " << data.size() << " "
                      << "top: "  << data.top()  << std::endl;
        }

        for (int i = 0; i < 5; i++) {
            std::cout << "size: " << data.size() << " "
                      << "top: "  << data.top()  << std::endl;
            data.pop();
        }
    }


    {
        // TEST FT::STACK
        std::cout << "   --- FT::STACK --- " << std::endl;
        ft::stack<int> data;
        for (int i = 0; i < 5; i++) {
            data.push((i+1)*2);
            std::cout << "size: " << data.size() << " "
                      << "top: "  << data.top()  << std::endl;
        }

        for (int i = 0; i < 5; i++) {
            std::cout << "size: " << data.size() << " "
                      << "top: "  << data.top()  << std::endl;
            data.pop();
        }
    }


}