#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <memory>
#include <iostream>
#include <algorithm>
#include <type_traits> // todo - to delete
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
			typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL) // TODO - replace std::is_integral by ft::is_integral
	: vector(alloc) {
		// std::cout << "iterator vector constructor called" << std::endl;
		assign(first, last);
	}

	vector(const vector<T,allocator_type>& src)
	: vector(src.get_allocator()) {
		// std::cout << "copy vector constructor called" << std::endl;
		assign(src.begin(), src.end());
	}

	~vector() {
		clear();
		_alloc.deallocate(_start, capacity());
	}
	
	// vector<T,allocator_type>& operator=(const vector<T,allocator_type>& x);

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL) { // TODO - replace std::is_integral by ft::is_integral
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
	const_iterator begin() const { return _start; }
	iterator end() { return _end; }
	const_iterator end() const { return _end; }
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	// // 23.2.4.2 capacity:
	size_type size() const {
		return _end - _start;
	}

	size_type max_size() const {
		return _alloc.max_size();
	}

	// void resize(size_type sz, T c = T());
	
	size_type capacity() const {
		return _end_capa - _start;
	}

	// bool empty() const;
	void reserve(size_type n) {
		// TODO : handle n > max_size()

		if (n <= capacity()) return ;

		// std::cout << "Reserve " << n << " (current: " << capacity() << ")" << std::endl;
		size_type old_size = size();
		
		// allocate new space
		iterator new_start = _alloc.allocate(n);

		// copy elts to new reserved space
		for (size_type i = 0; i < old_size; i++)
			_alloc.construct(new_start + i, _start[i]);

		// destroy old elts
		for (size_type i = 0; i < old_size; i++)
			_alloc.destroy(_start + i);

		// deallocate old space
		_alloc.deallocate(_start, capacity());

		// update pointers
		_start = new_start;
		_end = _start + old_size;
		_end_capa = _start + n;
	}

	// // element access:
	// reference operator[](size_type n);
	// const_reference operator[](size_type n) const;
	// const_reference at(size_type n) const;
	// reference at(size_type n);
	// reference front();
	// const_reference front() const;
	// reference back();
	// const_reference back() const;

	// // 23.2.4.3 modifiers:
	void push_back(const T& v) {
		insert(_end, v);
	}
	// void pop_back();

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
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL) { // TODO - replace std::is_integral by ft::is_integral
		difference_type n = last - first;
		pos = _reserve_at(pos, n);
		_shiftRight(pos, n);
		for (size_type i = 0; first + i < last; i++)
			_alloc.construct(pos + i, *(first + i));
	}
	
	// iterator erase(iterator position);
	// iterator erase(iterator first, iterator last);
	// void swap(vector<T,Allocator>&);
	void clear() {
		for (iterator p = _start; p < _end_capa; p++) {
			_alloc.destroy(p);
		}
		_end = _start;
	}

private:
	allocator_type	_alloc;
	iterator		_start;
	iterator		_end;
	iterator		_end_capa;

	void _shiftRight(iterator pos, size_type n) {
		iterator new_end = end() + n;
		iterator new_pos = new_end - 1;
		for (iterator cur = end() - 1; cur >= pos; cur--, new_pos--) {
			_alloc.construct(new_pos, *cur);
		}
		_end = new_end;
	}

	iterator _reserve_at(iterator pos, size_type n) {
		if (size() + n <= capacity()) return pos;

		difference_type diff = pos - begin();
		reserve(std::max<size_type>(n, 2 * capacity()));
		return begin() + diff;
	}
};

// template <class T, class Allocator>
// bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// template <class T, class Allocator>
// bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// template <class T, class Allocator>
// bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// template <class T, class Allocator>
// bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// template <class T, class Allocator>
// bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// template <class T, class Allocator>
// bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// specialized algorithms:
// template <class T, class Allocator>
// void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

}

#endif