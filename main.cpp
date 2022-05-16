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
		// TEST STD::VECTOR.CONSTRUCTORS
		std::cout << std::endl << "   --- STD::VECTOR CONSTRUCTORS ---" << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);
		std::vector<int> v2(v1);
		std::vector<int> v3(v1.begin() + 1, v1.end() - 1);
		std::vector<int> v4(7, 3);
		print_vector(v1);
		print_vector(v2);
		print_vector(v3);
		print_vector(v4);
	}

	{
		// TEST FT::VECTOR.CONSTRUCTORS
		std::cout << std::endl << "   --- FT::VECTOR CONSTRUCTORS ---" << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);
		ft::vector<int> v2(v1);
		ft::vector<int> v3(v1.begin() + 1, v1.end() - 1);
		ft::vector<int> v4(7, 3);
		print_vector(v1);
		print_vector(v2);
		print_vector(v3);
		print_vector(v4);
	}

	{
		// TEST STD::VECTOR.OPERATOR==
		std::cout << std::endl << "   --- STD::VECTOR.OPERATOR= ---" << std::endl;

		std::vector<int> foo (3,0);
  		std::vector<int> bar (5,0);
		print_vector(foo);
		print_vector(bar);

		bar = foo;
		foo = std::vector<int>();

		print_vector(foo);
		print_vector(bar);
	}

	{
		// TEST FT::VECTOR.OPERATOR==
		std::cout << std::endl << "   --- FT::VECTOR.OPERATOR= ---" << std::endl;
		
		ft::vector<int> foo (3,0);
  		ft::vector<int> bar (5,0);
		print_vector(foo);
		print_vector(bar);

		bar = foo;
		foo = ft::vector<int>();
		print_vector(foo);
		print_vector(bar);
	}


	{
		// TEST STD::VECTOR.INSERT(POS, N, VAL)
		std::cout << std::endl << "   --- STD::VECTOR.INSERT(POS, N, VAL) ---" << std::endl;

		std::vector<int> v;
		v.insert(v.begin(), 7, 3);
		print_vector(v);
		v.insert(v.begin() + 3, 4);
		print_vector(v);
		v.insert(v.begin() + 4, 3, 42);
		print_vector(v);
	}

	{
		// TEST STD::VECTOR.INSERT(POS, N, VAL)
		std::cout << std::endl << "   --- FT::VECTOR.INSERT(POS, N, VAL) ---" << std::endl;

		ft::vector<int> v;
		v.insert(v.begin(), 7, 3);
		print_vector(v);
		v.insert(v.begin() + 3, 4);
		print_vector(v);
		v.insert(v.begin() + 4, 3, 42);
		print_vector(v);
	}

	{
		// TEST STD::VECTOR.INSERT(POS, FIRST, LAST)
		std::cout << std::endl << "   --- STD::VECTOR.INSERT(POS, FIRST, LAST) ---" << std::endl;

		std::vector<int> v1(7, 3);
		std::vector<int> v2;

		for (int i = 0; i < 7; i++)
			v2.push_back(i);

		print_vector(v1);
		print_vector(v2);

		v1.insert(v1.begin() + 3, v2.begin() + 1, v2.begin() + 6);
		print_vector(v1);
	}

	{
		// TEST FT::VECTOR.INSERT(POS, FIRST, LAST)
		std::cout << std::endl << "   --- FT::VECTOR.INSERT(POS, FIRST, LAST) ---" << std::endl;

		ft::vector<int> v1(7, 3);
		ft::vector<int> v2;

		for (int i = 0; i < 7; i++)
			v2.push_back(i);

		print_vector(v1);
		print_vector(v2);

		v1.insert(v1.begin() + 3, v2.begin() + 1, v2.begin() + 6);
		print_vector(v1);
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

        std::vector<int> v2(v1);
		print_vector(v2);
        v2.push_back(11);
		print_vector(v2);

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

        ft::vector<int> v2(v1);
		print_vector(v2);
        v2.push_back(11);
		print_vector(v2);

        ft::vector<int> v3(10, 3);
		print_vector(v3);

    }

	{
		std::cout << std::endl << "   --- STD::VECTOR.EMPTY --- " << std::endl;

		std::vector<int> v1;
		std::vector<int> v2(0,0);
		std::vector<int> v3(v1);
		std::vector<int> v4(v1);
		v4.push_back(3);

		std::cout	<<  "v1:" << v1.empty()
					<< " v2:" << v2.empty()
					<< " v3:" << v3.empty()
					<< " v4:" << v4.empty() << std::endl;
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.EMPTY --- " << std::endl;

		ft::vector<int> v1;
		ft::vector<int> v2(0,0);
		ft::vector<int> v3(v1);
		ft::vector<int> v4(v1);
		v4.push_back(3);

		std::cout	<<  "v1:" << v1.empty()
					<< " v2:" << v2.empty()
					<< " v3:" << v3.empty()
					<< " v4:" << v4.empty() << std::endl;
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR.ERASE(POS) --- " << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.ERASE(POS) --- " << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR.ERASE(FIRST, LAST) --- " << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 1, v1.begin() + 5);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.ERASE(FIRST, LAST) --- " << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 1, v1.begin() + 5);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR.RESIZE --- " << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.resize(10);
		print_vector(v1);
		v1.resize(3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.RESIZE --- " << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.resize(10);
		print_vector(v1);
		v1.resize(3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR.POPBACK --- " << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.pop_back();
		print_vector(v1);
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.POPBACK --- " << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.pop_back();
		print_vector(v1);
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR - ELEMENT ACCESS --- " << std::endl;

		std::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		std::cout <<  "v1[2]:" << v1[2]
				  << " v1.at(2):" << v1.at(2)
				  << " v1.front():" << v1.front()
				  << " v1.back():" << v1.back() << std::endl;
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR - ELEMENT ACCESS --- " << std::endl;

		ft::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		std::cout <<  "v1[2]:" << v1[2]
				  << " v1.at(2):" << v1.at(2)
				  << " v1.front():" << v1.front()
				  << " v1.back():" << v1.back() << std::endl;
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR.SWAP --- " << std::endl;

		std::vector<int> foo (3,100);
		std::vector<int> bar (5,200);

		print_vector(foo);
		print_vector(bar);
		foo.swap(bar);
		print_vector(foo);
		print_vector(bar);
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR.SWAP --- " << std::endl;

		ft::vector<int> foo (3,100);
		ft::vector<int> bar (5,200);

		print_vector(foo);
		print_vector(bar);
		foo.swap(bar);
		print_vector(foo);
		print_vector(bar);
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR COMPARAISON OPERATORS --- " << std::endl;

		std::vector<int> foo (3,100);
		std::vector<int> bar(foo);
		std::vector<int> baz (4,42);

		print_vector(foo);
		print_vector(bar);
		print_vector(baz);

		std::cout << "foo==bar:" << (foo == bar) << " foo==baz:" << (foo == baz) << " bar==baz:" << (bar == baz) << std::endl;
		std::cout << "foo!=bar:" << (foo != bar) << " foo!=baz:" << (foo != baz) << " bar!=baz:" << (bar != baz) << std::endl;
		std::cout << "foo<bar:" << (foo < bar) << " foo<baz:" << (foo < baz) << " bar<baz:" << (bar < baz) << std::endl;
		std::cout << "foo<=bar:" << (foo <= bar) << " foo<=baz:" << (foo <= baz) << " bar<=baz:" << (bar <= baz) << std::endl;
		std::cout << "foo>bar:" << (foo > bar) << " foo>baz:" << (foo > baz) << " bar>baz:" << (bar > baz) << std::endl;
		std::cout << "foo>=bar:" << (foo >= bar) << " foo>=baz:" << (foo >= baz) << " bar>=baz:" << (bar >= baz) << std::endl;
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR COMPARAISON OPERATORS --- " << std::endl;

		ft::vector<int> foo (3,100);
		ft::vector<int> bar(foo);
		ft::vector<int> baz (4,42);

		print_vector(foo);
		print_vector(bar);
		print_vector(baz);

		std::cout << "foo==bar:" << (foo == bar) << " foo==baz:" << (foo == baz) << " bar==baz:" << (bar == baz) << std::endl;
		std::cout << "foo!=bar:" << (foo != bar) << " foo!=baz:" << (foo != baz) << " bar!=baz:" << (bar != baz) << std::endl;
		std::cout << "foo<bar:" << (foo < bar) << " foo<baz:" << (foo < baz) << " bar<baz:" << (bar < baz) << std::endl;
		std::cout << "foo<=bar:" << (foo <= bar) << " foo<=baz:" << (foo <= baz) << " bar<=baz:" << (bar <= baz) << std::endl;
		std::cout << "foo>bar:" << (foo > bar) << " foo>baz:" << (foo > baz) << " bar>baz:" << (bar > baz) << std::endl;
		std::cout << "foo>=bar:" << (foo >= bar) << " foo>=baz:" << (foo >= baz) << " bar>=baz:" << (bar >= baz) << std::endl;
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