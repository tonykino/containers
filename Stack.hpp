#ifndef STACK_TPP
#define STACK_TPP

#include "Vector.hpp"

namespace ft {
	
template <class T, class Container = ft::vector<T> >
class stack {
public:
	typedef Container container_type;
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;

protected:
	Container c;

public:
	explicit stack(const Container& ctnr = Container()): c(ctnr) {}
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	value_type& top() { return c.back(); }
	const value_type& top() const { return c.back(); }
	void push(const value_type& x) { c.push_back(x); }
	void pop() { c.pop_back(); }

	friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c == rhs.c;
	}

	friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c != rhs.c;
	}

	friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c < rhs.c;
	}

	friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c <= rhs.c;
	}

	friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c > rhs.c;
	}

	friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c >= rhs.c;
	}
};

}

#endif