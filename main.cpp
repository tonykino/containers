#include <iostream>
#include <vector>
#include <stack>
#include "Stack.hpp"
#include "Vector.hpp"

class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) {
	o << rhs.get();
	return o;
}

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

	// {
	// 	std::cout << std::endl << "   --- STD::VECTOR CONST ITERATOR ---" << std::endl;

	// 	std::vector<int>			test(3, 3);

	// 	std::cout << "self assignation test\n";
	// 	std::vector<std::vector<int> >	self_assign;
	// 	std::vector<std::vector<int> >	*ptr = &self_assign;
	// 	std::vector<std::vector<int> >	*ptr2 = &self_assign;

	// 	self_assign.assign(4, test);
	// 	*ptr = *ptr2;

	// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
	// //	self_assign = self_assign; //compiler doesn't like it!



	// 	std::vector<std::vector<int> > JOHN;
	// 	std::vector<std::vector<int> > BOB(5, test);
	// 	std::cout << "BOB(5, test(test, 5)) : \n";
	// 	for (size_t i = 0; i < BOB.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < BOB[i].size(); j++)
	// 			std::cout << BOB[i][j] << ' ';
	// 		std::cout << '\n';
	// 	}
	// 	std::vector<std::vector<int> > MIKE(BOB);

	// 	// CTORs
	// 	std::cout << "\nCTORS\n";
	// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// 	// RESIZE
	// 	size_t	bob_resize = 2;
	// 	std::cout << "\nRESIZE\n";
	// 	BOB.resize(bob_resize);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_resize)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	// 	size_t	mike_resize = 9;
	// 	bob_resize = 0;
		
	// 	BOB.resize(bob_resize);
	// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	// 	MIKE.resize(mike_resize, test);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_resize)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= mike_resize)
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		{
	// 			std::cout << MIKE[i][j] << ' ';
	// 		}
	// 	std::cout << std::endl;
	// 	}
	// 	// RESERVE
	// 	std::cout << "\nRESERVE\n";

	// 	size_t	john_reserve = 0;
	// 	size_t	bob_reserve = 3;
	// 	size_t	mike_reserve = 4;

	// 	JOHN.reserve(john_reserve);
	// 	BOB.reserve(bob_reserve);
	// 	MIKE.reserve(mike_reserve);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= john_reserve)
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_reserve)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= mike_reserve)
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			std::cout << MIKE[i][j] << ' ';
	// 	std::cout << std::endl;
	// 	}

	// 	//AT
	// 	std::cout << "\nAT\n";
	// 	try
	// 	{
	// 		std::cout << MIKE.at(2).front() << '\n';
	// 		std::cout << MIKE.at(87).back() << '\n';
	// 	}
	// 	catch (std::out_of_range& oor)
	// 	{
	// 		(void)oor;
	// 		std::cout << "OOR error caught\n";
	// 	}

	// 	// FRONT / BACK
	// 	std::cout << "\nFRONT / BACK\n";
	// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	// 	//ASSIGN
	// 	std::cout << "\nASSIGN\n";
	// 	test.assign(3, 17);
	// 	BOB.assign(3, test);

	// 	//ASSIGN RANGE
	// 	std::cout << "\nASSIGN RANGE\n";
	// 	std::vector<std::vector<int> >	assign_range;
	// 	assign_range.assign(8, test);
	// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	// 	//EMPTY
	// 	std::cout << "\nEMPTY\n";
	// 	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	// 	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	// 	//PUSH/POP_BACK
	// 	std::cout << "\nPUSH/POP_BACK\n";
	// 	test.assign(2, 42);
	// 	BOB.push_back(test);
	// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	// 	BOB.pop_back();
	// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	// 	//INSERT
	// 	std::cout << "\nINSERT\n";
	// 	std::vector<std::vector<int> >	insert_in_me;
	// 	for (int i = 0; i < 15; i++)
	// 	{
	// 		std::vector<int>	j(2, i);
	// 		insert_in_me.push_back(j);
	// 	}
	// 	for (size_t i = 0; i < insert_in_me.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 			std::cout << insert_in_me.at(i).at(j) << ' ';
	// 		std::cout << '\n';
	// 	}

	// 	std::vector<std::vector<int> >::iterator	tmp;
	// 	test.assign(23, 19);
	// 	tmp = insert_in_me.begin() + 4;
	// 	insert_in_me.insert(tmp, 8, test);
	// 	for (size_t i = 0; i < insert_in_me.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 			std::cout << insert_in_me.at(i).at(j) << ' ';
	// 		std::cout << '\n';
	// 	}

	// 	std::vector<std::vector<int> >::const_iterator const_it(insert_in_me.begin());
	// 	std::cout << "Const it.front() : " << std::endl;
	// 	std::cout << (*const_it).front() << '\n';


	// }

	// {
	// 	std::cout << std::endl << "   --- FT::VECTOR CONST ITERATOR ---" << std::endl;

	// 	ft::vector<int>			test(3, 3);

	// 	std::cout << "self assignation test\n";
	// 	ft::vector<ft::vector<int> >	self_assign;
	// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
	// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

	// 	self_assign.assign(4, test);
	// 	*ptr = *ptr2;

	// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
	// //	self_assign = self_assign; //compiler doesn't like it!



	// 	ft::vector<ft::vector<int> > JOHN;
	// 	ft::vector<ft::vector<int> > BOB(5, test);
	// 	std::cout << "BOB(5, test(test, 5)) : \n";
	// 	for (size_t i = 0; i < BOB.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < BOB[i].size(); j++)
	// 			std::cout << BOB[i][j] << ' ';
	// 		std::cout << '\n';
	// 	}
	// 	ft::vector<ft::vector<int> > MIKE(BOB);

	// 	// CTORs
	// 	std::cout << "\nCTORS\n";
	// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// 	// RESIZE
	// 	size_t	bob_resize = 2;
	// 	std::cout << "\nRESIZE\n";
	// 	BOB.resize(bob_resize);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_resize)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	// 	size_t	mike_resize = 9;
	// 	bob_resize = 0;
		
	// 	BOB.resize(bob_resize);
	// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	// 	MIKE.resize(mike_resize, test);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_resize)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= mike_resize)
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 		{
	// 			std::cout << MIKE[i][j] << ' ';
	// 		}
	// 	std::cout << std::endl;
	// 	}
	// 	// RESERVE
	// 	std::cout << "\nRESERVE\n";

	// 	size_t	john_reserve = 0;
	// 	size_t	bob_reserve = 3;
	// 	size_t	mike_reserve = 4;

	// 	JOHN.reserve(john_reserve);
	// 	BOB.reserve(bob_reserve);
	// 	MIKE.reserve(mike_reserve);
	// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= john_reserve)
	// 		std::cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= bob_reserve)
	// 		std::cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= mike_reserve)
	// 		std::cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			std::cout << MIKE[i][j] << ' ';
	// 	std::cout << std::endl;
	// 	}

	// 	//AT
	// 	std::cout << "\nAT\n";
	// 	try
	// 	{
	// 		std::cout << MIKE.at(2).front() << '\n';
	// 		std::cout << MIKE.at(87).back() << '\n';
	// 	}
	// 	catch (std::out_of_range& oor)
	// 	{
	// 		(void)oor;
	// 		std::cout << "OOR error caught\n";
	// 	}

	// 	// FRONT / BACK
	// 	std::cout << "\nFRONT / BACK\n";
	// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	// 	//ASSIGN
	// 	std::cout << "\nASSIGN\n";
	// 	test.assign(3, 17);
	// 	BOB.assign(3, test);

	// 	//ASSIGN RANGE
	// 	std::cout << "\nASSIGN RANGE\n";
	// 	ft::vector<ft::vector<int> >	assign_range;
	// 	assign_range.assign(8, test);
	// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	// 	//EMPTY
	// 	std::cout << "\nEMPTY\n";
	// 	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	// 	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	// 	//PUSH/POP_BACK
	// 	std::cout << "\nPUSH/POP_BACK\n";
	// 	test.assign(2, 42);
	// 	BOB.push_back(test);
	// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	// 	BOB.pop_back();
	// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	// 	//INSERT
	// 	std::cout << "\nINSERT\n";
	// 	ft::vector<ft::vector<int> >	insert_in_me;
	// 	for (int i = 0; i < 15; i++)
	// 	{
	// 		ft::vector<int>	j(2, i);
	// 		insert_in_me.push_back(j);
	// 	}
	// 	for (size_t i = 0; i < insert_in_me.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 			std::cout << insert_in_me.at(i).at(j) << ' ';
	// 		std::cout << '\n';
	// 	}

	// 	ft::vector<ft::vector<int> >::iterator	tmp;
	// 	test.assign(23, 19);
	// 	tmp = insert_in_me.begin() + 4;
	// 	insert_in_me.insert(tmp, 8, test);
	// 	for (size_t i = 0; i < insert_in_me.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
	// 			std::cout << insert_in_me.at(i).at(j) << ' ';
	// 		std::cout << '\n';
	// 	}

	// 	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
	// 	std::cout << "Const it.front() : " << std::endl;
	// 	std::cout << (*const_it).front() << '\n';


	// 	//INSERT
	// 	std::cout << "\nINSERT\n";
	// 	ft::vector<ft::vector<int> >	std_insert_in_me;
	// 	for (int i = 0; i < 15; i++)
	// 		std_insert_in_me.push_back(test);
	// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 		std::cout << std_insert_in_me.at(i).front() << ' ';
	// 	std::cout << '\n';

	// 	ft::vector<ft::vector<int> >::iterator	std_tmp;
	// 	std_tmp = std_insert_in_me.begin() + 4;
	// 	std_insert_in_me.insert(std_tmp, 8, test);
	// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 		std::cout << std_insert_in_me.at(i).back() << ' ';
	// 	std::cout << '\n';


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
		// TEST STD::VECTOR.OPERATOR=
		std::cout << std::endl << "   --- STD::VECTOR.OPERATOR= ---" << std::endl;

		std::vector<int> foo (3,0);
  		std::vector<int> bar (5,0);
		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);

		bar = foo;
		foo = std::vector<int>();

		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);
	}

	{
		// TEST FT::VECTOR.OPERATOR=
		std::cout << std::endl << "   --- FT::VECTOR.OPERATOR= ---" << std::endl;
		
		ft::vector<int> foo (3,0);
  		ft::vector<int> bar (5,0);
		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);

		bar = foo;
		foo = ft::vector<int>();
		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);
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
		v.insert(v.begin() + 8, 100, 100);
		print_vector(v);
		v.insert(v.end() - 1, 0, 42);
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
		v.insert(v.begin() + 8, 100, 100);
		print_vector(v);
		v.insert(v.end() - 1, 0, 42);
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
		swap(foo, bar);
		print_vector(foo);
		print_vector(bar);

		std::cout << std::endl;
		
		std::vector<int> mike(83, 8);
		std::vector<int> bob(84, 7);
		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);

		mike.erase(mike.begin() + 5, mike.end());
		mike.insert(mike.begin() + 5, 4, 3);
		bob.erase(bob.begin() + 42, bob.end());
		
		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);

		bob.swap(mike);

		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);

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
		swap(foo, bar);
		print_vector(foo);
		print_vector(bar);

		std::cout << std::endl;
		
		ft::vector<int> mike(83, 8);
		ft::vector<int> bob(84, 7);
		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);

		mike.erase(mike.begin() + 5, mike.end());
		mike.insert(mike.begin() + 5, 4, 3);
		bob.erase(bob.begin() + 42, bob.end());
		
		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);

		bob.swap(mike);

		std::cout << "mike "; print_vector(mike);
		std::cout << "bob "; print_vector(bob);
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

	{
		std::cout << std::endl << "   --- STD::VECTOR ANOTHER INSERT TEST --- " << std::endl;

		std::vector<int> v1 (3,100);
		std::vector<int>::iterator it;

		it = v1.begin();
		it = v1.insert ( it , 200 );

		v1.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = v1.begin();

		std::vector<int> v2 (2,400);
		v1.insert (it+2,v2.begin(),v2.end());

		int myarray [] = { 501,502,503 };
		v1.insert (v1.begin(), myarray, myarray+3);

		std::cout << "v1 contains:";
		for (it=v1.begin(); it<v1.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::cout << std::endl << "   --- FT::VECTOR ANOTHER INSERT TEST --- " << std::endl;

		ft::vector<int> v1 (3,100);
		ft::vector<int>::iterator it;

		it = v1.begin();
		it = v1.insert ( it , 200 );

		v1.insert (it,2,300);
		
		// "it" no longer valid, get a new one:
		it = v1.begin();

		ft::vector<int> v2 (2,400);
		v1.insert (v1.begin() + 2, v2.begin(),v2.end());

		int myarray [] = { 501,502,503 };
		v1.insert (v1.begin(), myarray, myarray+3);

		std::cout << "v1 contains:";
		for (it=v1.begin(); it<v1.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR AWESOME TESTS ---" << std::endl;
	
		std::vector<Awesome> test(21, 12);
		print_vector(test);
		std::vector<Awesome> test2;
		print_vector(test2);
		test2.push_back(12);
		test2.push_back(8);
		test2.push_back(16);
		print_vector(test2);
		std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
		test.assign(test2.begin(), test2.end());
		print_vector(test);
		test = test2;
		print_vector(test);
		std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
		test.insert(test.end(), test2.begin(), test2.end());
		print_vector(test);
		test.insert(test.begin(), test2.begin(), test2.end());
		test2 = test;
		print_vector(test);
		std::cout << "end awesome test" << std::endl;
	}

	{
		std::cout << std::endl << "   --- STD::VECTOR AWESOME TESTS ---" << std::endl;
	
		ft::vector<Awesome> test(21, 12);
		std::cout << "coucou\n"; 
		print_vector(test);
		ft::vector<Awesome> test2;
		print_vector(test2);
		test2.push_back(12);
		test2.push_back(8);
		test2.push_back(16);
		print_vector(test2);
		std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
		test.assign(test2.begin(), test2.end());
		print_vector(test);
		test = test2;
		print_vector(test);
		std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
		test.insert(test.end(), test2.begin(), test2.end());
		print_vector(test);
		test.insert(test.begin(), test2.begin(), test2.end());
		test2 = test;
		print_vector(test);
		std::cout << "end awesome test" << std::endl;
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