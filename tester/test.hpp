#ifndef TEST_HPP
#define TEST_HPP

// #ifdef STD
// 	#include <vector>
// 	#include <map>
// 	#include <stack>
// 	#define NAMESPACE std;
// #else
// 	#include "iterator_traits.hpp"
// 	#include "map.hpp"
// 	#include "pair.hpp"
// 	#include "rb_iterator.hpp"
// 	#include "rb_node.hpp"
// 	#include "rb_tree.hpp"
// 	#include "reverse_iterator.hpp"
// 	#include "stack.hpp"
// 	#include "test.hpp"
// 	#include "type_traits.hpp"
// 	#include "vector.hpp"
// 	// #include "lexicographical_compare.hpp"
// 	#define NAMESPACE ft;
// #endif

#ifdef STD
	#define NS std
#else
	#define NS ft
#endif

#include <utility>
#include <string>
#include <sstream>
#include <iostream>

void test_vector(void);
void test_stack(void);
void test_rbt(void);
void test_map(void);

#endif