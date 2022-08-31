#include "test.hpp"
#include <deque>
#include <list>

#ifdef STD
	#include <stack>
#else
	#include "../stack.hpp"
#endif

void test_stack(void)
{
	{
		NS::stack<int> c1;
		for (int i = 0; i < 5; i++) {
			c1.push((i+1)*2);
			std::cout << "size: " << c1.size() << " "
						<< "top: "  << c1.top()  << std::endl;
		}

		NS::stack<int> c2(c1);

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
		NS::stack<int, std::deque<int> > c1;
		for (int i = 0; i < 5; i++) {
			c1.push((i+1)*2);
			std::cout << "size: " << c1.size() << " "
						<< "top: "  << c1.top()  << std::endl;
		}

		NS::stack<int, std::deque<int> > c2(c1);

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
		NS::stack<int, std::list<int> > c1;
		for (int i = 0; i < 5; i++) {
			c1.push((i+1)*2);
			std::cout << "size: " << c1.size() << " "
						<< "top: "  << c1.top()  << std::endl;
		}

		NS::stack<int, std::list<int> > c2(c1);

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

}