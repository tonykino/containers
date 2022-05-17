#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <memory>
#include <iostream>
#include <algorithm>
#include "enable_if.hpp"

namespace ft {
	
template <class T, class Allocator = std::allocator<T> >
class vector {
public:
	// types:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;

	// typedef std::iterator<pointer, value_type> iterator; // TODO
	typedef pointer iterator; // TODO, should be the above line ?
	// typedef std::iterator<const_pointer, value_type> const_iterator; // TODO
	typedef const_pointer const_iterator; // TODO, should be the above line ?
	typedef std::reverse_iterator<iterator> reverse_iterator; // TODO, use ft::reverse_iterator
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // TODO, use ft::reverse_iterator
	
	typedef std::ptrdiff_t difference_type;
	typedef std::size_t size_type;

	// 23.2.4.1 construct/copy/destroy:	
	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(_alloc.allocate(0)), _end(_start), _end_capa(_end) {
		// std::cout << "default vector constructor called" << std::endl;
	}

	explicit vector(size_type n, const T& v = T(), const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(_alloc.allocate(n)), _end(_start + n), _end_capa(_end) {
		// std::cout << "n v vector constructor called" << std::endl;
		assign(n, v);
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
	: _alloc(alloc), _start(_alloc.allocate(0)), _end(_start), _end_capa(_end) {
		// std::cout << "iterator vector constructor called" << std::endl;
		assign(first, last);
	}

	vector(const vector<T,allocator_type>& src)
	: _alloc(src.get_allocator()), _start(src.get_allocator().allocate(0)), _end(_start), _end_capa(_end) {
		// std::cout << "copy vector constructor called" << std::endl;
		assign(src.begin(), src.end());
	}

	~vector() {
		clear();
		_alloc.deallocate(_start, capacity());
	}
	
	vector<T,allocator_type>& operator=(const vector<T,allocator_type>& rhs) { // TODO - bugfix to do here, check test operator= and swap to see inconsistency
		clear();
		assign(rhs.begin(), rhs.end());
		return *this;
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
		clear();
		insert(begin(), first, last);
	}

	void assign(size_type n, const T& val) {
		clear();
		insert(begin(), n, val);
	}

	allocator_type get_allocator() const { return _alloc; }

	// iterators:
	iterator begin() { return _start; }
	iterator end()	 { return _end; }
	const_iterator begin() const { return _start; }
	const_iterator end()   const { return _end; }
	reverse_iterator rbegin() { return reverse_iterator(_end); }
	reverse_iterator rend()   { return reverse_iterator(_start); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(_end); }
	const_reverse_iterator rend()   const { return const_reverse_iterator(_start); }

	// 23.2.4.2 capacity:
	size_type size()	 const { return _end - _start; }
	size_type max_size() const { return _alloc.max_size(); }
	size_type capacity() const { return _end_capa - _start; }
	bool	  empty() 	 const { return size() == 0; }

	void resize(size_type n, value_type v = value_type()) {
		if (n < size())
			erase(begin() + n, end());
		else if (n > size())
			insert(end(), n - size(), v);
	}


	void reserve(size_type n) {
		if (n > max_size()) throw std::length_error("vector::reserve");
		if (n <= capacity()) return ;

		// std::cout << "Reserve " << n << std::endl;
		size_type old_size = size();
		iterator new_start = _alloc.allocate(n);

		for (size_type i = 0; i < old_size; i++)
			_alloc.construct(new_start + i, _start[i]);

		for (size_type i = 0; i < old_size; i++)
			_alloc.destroy(_start + i);

		_alloc.deallocate(_start, capacity());
		_start = new_start;
		_end = _start + old_size;
		_end_capa = _start + n;
	}

	// element access:
	reference		operator[](size_type pos)		{ return begin()[pos]; }
	const_reference operator[](size_type pos) const { return begin()[pos]; }
	reference 		front()		  { return begin()[0]; }
	const_reference front() const { return begin()[0]; }
	reference 		back()		  { return begin()[size() - 1]; }
	const_reference back() 	const { return begin()[size() - 1]; }

	const_reference at(size_type pos) const {
		if (pos >= size()) throw std::out_of_range("ft::vector::at");

		return begin()[pos];
	}

	reference at(size_type pos) {
		if (pos >= size()) throw std::out_of_range("ft::vector::at");

		return begin()[pos];
	}

	// 23.2.4.3 modifiers:
	void push_back(const T& v) { insert(_end, v); }
	void pop_back() { erase(_end - 1); }

	iterator insert(iterator pos, const T& v) {
		insert(pos, 1, v);
		return pos;
	}

	void insert(iterator pos, size_type n, const T& v) {
		pos = _reserve_at(pos, n);
		_shiftRight(pos, n);
		for (iterator cur = pos; cur < pos + n; cur++)
			_alloc.construct(cur, v);
	}

	template <class InputIterator>
	void insert(iterator pos, InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
		difference_type n = last - first;
		pos = _reserve_at(pos, n);
		_shiftRight(pos, n);
		for (size_type i = 0; first + i < last; i++)
			_alloc.construct(pos + i, *(first + i));
	}
	
	iterator erase(iterator pos) {
		_shiftLeft(pos, 1);
		return pos;
	}

	iterator erase(iterator first, iterator last) {
		_shiftLeft(first, last - first);
		return first;
	}

	void swap(vector & x) {
		allocator_type	tmp_alloc = x._alloc;
		iterator		tmp_start = x._start;
		iterator		tmp_end = x._end;
		iterator		tmp_end_capa = x._end_capa;

		x._alloc = _alloc;
		x._start = _start;
		x._end = _end;
		x._end_capa = _end_capa;

		_alloc = tmp_alloc;
		_start = tmp_start;
		_end = tmp_end;
		_end_capa = tmp_end_capa;
	}

	void clear() {
		erase(begin(), end());
	}

	void print() {
		std::cout << "s:" << size() << " c:" << capacity() << " | "; // TODO - To delete
		for (iterator it = begin(); it < end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	void print() const {
		std::cout << "s:" << size() << " c:" << capacity() << " | "; // TODO - To delete
		for (size_type i = 0; begin() + i < end(); i++)
			std::cout << begin()[i] << " ";
		std::cout << std::endl;
	}

private:
	allocator_type	_alloc;
	iterator		_start;
	iterator		_end;
	iterator		_end_capa;

	void _shiftRight(iterator pos, size_type n) {
		if (n == 0) return;

		iterator new_end = end() + n;
		iterator new_pos = new_end - 1;
		for (iterator it = end() - 1; it >= pos; it--, new_pos--) {
			_alloc.construct(new_pos, *it);
			_alloc.destroy(it);
		}
		_end = new_end;
	}

	void _shiftLeft(iterator pos, size_type n) {
		if (n == 0) return;
		
		for (iterator it = pos; it < end() - n; it++) {
			_alloc.destroy(it);
			_alloc.construct(it, *(it + n));
			_alloc.destroy(it + n);
		}
		_end = end() - n;
	}

	iterator _reserve_at(iterator pos, size_type n) {
		if (size() + n <= capacity()) return pos;

		difference_type diff = pos - begin();
		// std::cout << "n:" << n << " size:" << size() << std::endl;
		reserve(std::max<size_type>(n + size(), 2 * size()));
		return begin() + diff;
	}
};

template <class T, class Allocator>
bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	if (x.size() != y.size()) return false;

	for (size_t i = 0; i < x.size(); i++) { // todo - use ft::equal algorithm
		if (x[i] != y[i]) return false;
	}
	return true;
}

template <class T, class Allocator>
bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); // todo - use ft::lexicographical_compare
}

template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	return !(x == y);
}

template <class T, class Allocator>
bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	return y < x;
}

template <class T, class Allocator>
bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	return !(x < y);
}

template <class T, class Allocator>
bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
	return !(y < x);
}

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y) { x.swap(y); }


}
#endif