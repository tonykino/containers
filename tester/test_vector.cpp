#include "test.hpp"

#ifdef STD
	#include <vector>
#else
	#include "../vector.hpp"
#endif

class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; }
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
		void operator+=(int rhs) { _n += rhs; }
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

void test_vector(void)
{

	{
		std::cout << std::endl << "   --- VECTOR CONSTRUCTORS ---" << std::endl;

		NS::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);
		NS::vector<int> v2(v1);
		NS::vector<int> v3(v1.begin() + 1, v1.end() - 1);
		NS::vector<int> v4(7, 3);
		print_vector(v1);
		print_vector(v2);
		print_vector(v3);
		print_vector(v4);
	}

	{
		std::cout << std::endl << "   --- VECTOR OPERATOR= ---" << std::endl;
		
		NS::vector<int> foo (3,0);
  		NS::vector<int> bar (5,0);
		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);

		bar = foo;
		foo = NS::vector<int>();
		std::cout << "foo: "; print_vector(foo);
		std::cout << "bar: "; print_vector(bar);
	}

	{
		std::cout << std::endl << "   --- VECTOR.INSERT(POS, N, VAL) ---" << std::endl;

		NS::vector<int> v;
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
		std::cout << std::endl << "   --- VECTOR.INSERT(POS, FIRST, LAST) ---" << std::endl;

		NS::vector<int> v1(7, 3);
		NS::vector<int> v2;

		for (int i = 0; i < 7; i++)
			v2.push_back(i);

		print_vector(v1);
		print_vector(v2);

		v1.insert(v1.begin() + 3, v2.begin() + 1, v2.begin() + 6);
		print_vector(v1);
	}

    {
		std::cout << std::endl << "   --- VECTOR.PUSH_BACK --- " << std::endl;

        NS::vector<int> v1;
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

        NS::vector<int> v2(v1);
		print_vector(v2);
        v2.push_back(11);
		print_vector(v2);

        NS::vector<int> v3(10, 3);
		print_vector(v3);

    }

	{
		std::cout << std::endl << "   --- VECTOR.EMPTY --- " << std::endl;

		NS::vector<int> v1;
		NS::vector<int> v2(0,0);
		NS::vector<int> v3(v1);
		NS::vector<int> v4(v1);
		v4.push_back(3);

		std::cout	<<  "v1:" << v1.empty()
					<< " v2:" << v2.empty()
					<< " v3:" << v3.empty()
					<< " v4:" << v4.empty() << std::endl;
	}

	{
		std::cout << std::endl << "   --- VECTOR.ERASE(POS) --- " << std::endl;

		NS::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- VECTOR.ERASE(FIRST, LAST) --- " << std::endl;

		NS::vector<int> v1;
		for (int i = 0; i < 7; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.erase(v1.begin() + 1, v1.begin() + 5);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- VECTOR.RESIZE --- " << std::endl;

		NS::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		v1.resize(10);
		print_vector(v1);
		v1.resize(3);
		print_vector(v1);
	}

	{
		std::cout << std::endl << "   --- VECTOR.POPBACK --- " << std::endl;

		NS::vector<int> v1;
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
		std::cout << std::endl << "   --- VECTOR - ELEMENT ACCESS --- " << std::endl;

		NS::vector<int> v1;
		for (int i = 0; i < 6; i++)
			v1.push_back(i);

		print_vector(v1);
		std::cout <<  "v1[2]:" << v1[2]
				  << " v1.at(2):" << v1.at(2)
				  << " v1.front():" << v1.front()
				  << " v1.back():" << v1.back() << std::endl;
	}

	{
		std::cout << std::endl << "   --- VECTOR.SWAP --- " << std::endl;

		NS::vector<int> foo (3,100);
		NS::vector<int> bar (5,200);

		print_vector(foo);
		print_vector(bar);
		foo.swap(bar);
		print_vector(foo);
		print_vector(bar);
		swap(foo, bar);
		print_vector(foo);
		print_vector(bar);

		std::cout << std::endl;
		
		NS::vector<int> mike(83, 8);
		NS::vector<int> bob(84, 7);
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
		std::cout << std::endl << "   --- VECTOR COMPARAISON OPERATORS --- " << std::endl;

		NS::vector<int> foo (3,100);
		NS::vector<int> bar(foo);
		NS::vector<int> baz (4,42);

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
		std::cout << std::endl << "   --- VECTOR ANOTHER INSERT TEST --- " << std::endl;

		NS::vector<int> v1 (3,100);
		NS::vector<int>::iterator it;

		it = v1.begin();
		it = v1.insert ( it , 200 );

		v1.insert (it,2,300);
		
		it = v1.begin();

		NS::vector<int> v2 (2,400);
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
	
		NS::vector<Awesome> test(21, 12);
		print_vector(test);
		NS::vector<Awesome> test2;
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
}