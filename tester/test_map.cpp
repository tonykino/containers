#include "test.hpp"

#ifdef STD
	#include <map>
#else
	#include "../map.hpp"
#endif

template <typename T>
std::string to_string(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

template <typename T>
std::string print_pair(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second;
	return "";
}

template <typename T_MAP>
void	print_map(T_MAP const &mp)
{
	std::cout << "size: " << mp.size() << std::endl;
	typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
	std::cout << "Content is:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "- " << print_pair(it) << std::endl;
	std::cout << std::endl;
}

void test_map(void)
{
	{
		std::cout << std::endl << "   --- MAP CONSTRUCTORS ---" << std::endl;

		NS::map<int, std::string> foo;
		for (int i = 0; i < 7; i++)
			foo[i] = to_string(i);
		NS::map<int, std::string> bar(foo);
		NS::map<int, std::string> baz(foo.begin()++, foo.end()--);
		print_map(foo);
		print_map(bar);
		print_map(baz);
	}

	{
		std::cout << std::endl << "   --- MAP OPERATOR= ---" << std::endl;
		
		NS::map<int, std::string> foo;
		NS::map<int, std::string> bar;

		for (int i = 0; i < 7; i++)
			foo[i] = to_string(i);
		std::cout << "foo: "; print_map(foo);
		std::cout << "bar: "; print_map(bar);

		bar = foo;
		foo = NS::map<int, std::string>();
		std::cout << "foo: "; print_map(foo);
		std::cout << "bar: "; print_map(bar);
	}

	{
		std::cout << std::endl << "   --- MAP - ELEMENT ACCESS --- " << std::endl;

		NS::map<int, std::string> foo;
		for (int i = 0; i < 6; i++)
			foo[i] = to_string(i);

		print_map(foo);
		std::cout <<  "foo[2]:" << foo[2]
				  << " foo[4]:" << foo[4] << std::endl;
	}

	{
		std::cout << std::endl << "   --- MAP.INSERT ---" << std::endl;

		NS::map<std::string, std::string> foo;
		NS::pair<std::string, std::string> content = NS::make_pair<std::string, std::string>("Hola", "Quetal");
		foo.insert(foo.begin(), content);
		print_map(foo);
		foo.insert(foo.end(), NS::make_pair<std::string, std::string>("The foo", "bar baz"));
		print_map(foo);
		foo.insert(NS::make_pair<std::string, std::string>("Lorem", "ipsum"));
		print_map(foo);
	}

	{
		std::cout << std::endl << "   --- MAP.ERASE --- " << std::endl;

		NS::map<int, int> foo;
		NS::pair<int, int> content = NS::make_pair<int, int>(42, 1337);

		for (int i = 0; i < 20; i++)
			foo.insert(NS::make_pair<int, int>(i + 1, i * 3));
		foo.insert(content);

		print_map(foo);
		foo.erase(++foo.begin()); // erase(pos)
		print_map(foo);
		foo.erase(42); // erase(key)
		print_map(foo);
		foo.erase(++(foo.begin()++), (--foo.end())--); // erase(first, last)
		print_map(foo);
	}

	{
		std::cout << std::endl << "   --- MAP.SWAP --- " << std::endl;

		NS::map<int, int> foo;
		NS::map<int, int> bar;

		for (int i = 0; i < 20; i++) {
			foo.insert(NS::make_pair<int, int>(i + 5, (i + 2) * 3));
			bar.insert(NS::make_pair<int, int>(i + 12, i * 3 + 42));
		}

		print_map(foo);
		print_map(bar);
		foo.swap(bar);
		print_map(foo);
		print_map(bar);
		swap(foo, bar);
		print_map(foo);
		print_map(bar);

		NS::pair<int, int> content = NS::make_pair<int, int>(42, 1337);
		NS::pair<int, int> content2 = NS::make_pair<int, int>(19, 21);

		foo.erase(++foo.begin(), --foo.end());
		foo.insert(foo.begin(), content);
		bar.erase(15);
		bar.insert(content2);

		print_map(foo);
		print_map(bar);
		bar.swap(foo);
		print_map(foo);
		print_map(bar);
	}

	{
		std::cout << std::endl << "   --- MAP.EQUAL_RANGE --- " << std::endl;

		NS::map<char,int> foo;

		foo['a']=10;
		foo['b']=20;
		foo['c']=30;

		NS::pair<NS::map<char,int>::iterator, NS::map<char,int>::iterator> ret;
		ret = foo.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
  
	}

	{
		std::cout << std::endl << "   --- MAP.KEY_COMP --- " << std::endl;

		NS::map<char,int> foo;
    	NS::map<char,int>::key_compare comp = foo.key_comp();

		foo['a']=100;
		foo['b']=200;
		foo['c']=300;

		std::cout << "foo contains:\n";
		char highest = foo.begin()->first;
		NS::map<char,int>::iterator it = foo.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( comp((*it++).first, highest) );
	}

	{
		std::cout << std::endl << "   --- MAP.VALUE_COMP --- " << std::endl;

		NS::map<char,int> foo;
		foo['x']=1001;
		foo['y']=2002;
		foo['z']=3003;

		NS::pair<char,int> highest = *foo.begin();
		NS::map<char,int>::iterator it = foo.begin();
		do {
		std::cout << it->first << " => " << it->second << '\n';
		} while ( foo.value_comp()(*it++, highest) );

	}

	{
		std::cout << std::endl << "   --- MAP.LOWER_AND_UPPER_BOUND --- " << std::endl;
		NS::map<int, int> foo;
		unsigned int i = 1;

		while ( i < 500 )
		{
			foo.insert(NS::pair<int, int>(i, i*5));
			i++;
		}

		// test lower_bound function
		NS::map<int, int>::iterator it1 = foo.lower_bound(foo.find(i - 324)->first);
		std::cout << (*it1).first << std::endl;
		it1 = foo.lower_bound(foo.lower_bound(foo.find(15)->first)->first);
		std::cout << it1->second << std::endl;

		// test upper_bound function
		NS::map<int, int>::iterator it2 = foo.upper_bound(foo.find(i - 324)->first);
		std::cout << (*it2).first << std::endl;
		it2 = foo.upper_bound(foo.upper_bound(foo.find(15)->first)->first);
		std::cout << it2->second << std::endl;
	}
}
