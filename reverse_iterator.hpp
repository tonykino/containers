#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template<typename I>
class reverse_iterator {
	public:
	typedef I													iterator_type;
	typedef typename ft::iterator_traits<I>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<I>::value_type			value_type;
	typedef typename ft::iterator_traits<I>::difference_type	difference_type;
	typedef typename ft::iterator_traits<I>::pointer			pointer;
	typedef typename ft::iterator_traits<I>::reference			reference;

	reverse_iterator(): _it() {}
    explicit reverse_iterator(iterator_type x): _it(x) {}
	iterator_type base() const { return _it; }

	template<class U>
	reverse_iterator(const reverse_iterator<U>&src): _it(src.base()) {}

	template<class U>
	reverse_iterator& operator=(const reverse_iterator<U>& src) {
		_it = src.base();
		return *this;
	}

	reference operator*() const {
		I tmp = _it;
		return *--tmp;
	}

	pointer operator->() const {
		return &(operator*());
	}

	reverse_iterator& operator++() {
		_it--;
		return *this;
	}

	reverse_iterator& operator--() {
		_it++;
		return *this;
	}

	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		_it--;
		return tmp;
	}

	reverse_iterator operator--(int) {
		reverse_iterator tmp = *this;
		_it++;
		return tmp;
	}

	reverse_iterator operator+(difference_type n) const {
		return reverse_iterator(base() - n);
	}

	reverse_iterator operator-(difference_type n) const {
		return reverse_iterator(base() + n);
	}

	reverse_iterator operator+=(difference_type n) {
		_it -= n;
		return *this;
	}

	reverse_iterator operator-=(difference_type n) {
		_it += n;
		return *this;
	}

	reference operator[](difference_type n) const {
		return *(*this + n);
	}

    protected:
	I _it;

};

template<class I, class J>
bool operator==(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() == rhs.base();
}

template<class I, class J>
bool operator!=(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() != rhs.base();
}

template<class I, class J>
bool operator<(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() > rhs.base();
}

template<class I, class J>
bool operator<=(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() >= rhs.base();
}

template<class I, class J>
bool operator>(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() < rhs.base();
}

template<class I, class J>
bool operator>=(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return lhs.base() <= rhs.base();
}

template<class I>
reverse_iterator<I> operator+(typename ft::reverse_iterator<I>::difference_type n, const ft::reverse_iterator<I>&_it) {
	return _it + n;
}

template<class I, class J>
typename reverse_iterator<I>::difference_type operator-(const ft::reverse_iterator<I>&lhs, const ft::reverse_iterator<J>&rhs) {
	return rhs.base() - lhs.base();
}

template<class I>
I next(I first, typename ft::iterator_traits<I>::difference_type n = 1)
{
    for (typename ft::iterator_traits<I>::difference_type i = 0; i < n; i++)
		first++;
	return first;
}

template<class I>
I prev(I first, typename ft::iterator_traits<I>::difference_type n = 1)
{
    for (typename ft::iterator_traits<I>::difference_type i = 0; i < n; i++)
		first--;
	return first;
}

}

#endif