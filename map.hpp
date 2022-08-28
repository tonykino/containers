#ifndef MAP_TPP
#define MAP_TPP

#include <memory>
#include <iostream>
#include <algorithm>
#include <utility>
#include "rb_tree.hpp"
#include "rb_node.hpp"
#include "reverse_iterator.hpp"
#include "rb_iterator.hpp"
#include "pair.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

public:
	// types:   
	typedef Key key_type;
	typedef T mapped_type;
	typedef ft::pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef RBIterator<value_type> iterator;
	typedef RBConstIterator<value_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
	typedef std::size_t size_type;

	class value_compare: public std::binary_function<value_type, value_type, bool> {
		friend class map;
		
		protected:
		Compare comp;
		value_compare(Compare c): comp(c) {}

		public:
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	// 23.3.1.1 construct/copy/destroy:
	explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
	: _comp(comp), _alloc(alloc), _size(0) {
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
	: _comp(comp), _alloc(alloc), _size(0) {
		insert(first, last);
	}

	map(const map<Key, T, Compare, Allocator>& src)
	: _comp(src._comp), _alloc(src._alloc), _size(0) {
		*this = src;
	}

	~map() {
		clear();
	}

	map<Key, T, Compare, Allocator>& operator=(const map<Key, T, Compare, Allocator>& rhs) {
		clear();
		_comp = rhs._comp;
		_alloc = rhs._alloc;
		insert(rhs.begin(), rhs.end());
		return *this;
	}

	// // iterators:
	iterator begin() { return iterator((size() == 0) ? _tree.get_sentinel() : _tree.min()); }
	const_iterator begin() const { return const_iterator((size() == 0) ? _tree.get_sentinel() : _tree.min()); }
	iterator end() { return iterator(_tree.get_sentinel()); }
	const_iterator end() const { return const_iterator(_tree.get_sentinel()); }
	reverse_iterator rbegin() { return reverse_iterator(iterator((size() == 0) ? _tree.get_sentinel() : _tree.max())); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(const_iterator((size() == 0) ? _tree.get_sentinel() : _tree.max())); }
	reverse_iterator rend() { return reverse_iterator(iterator(_tree.get_sentinel())); }
	const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(_tree.get_sentinel())); }

	// // capacity:
	size_type size()	 const { return _size; }
	size_type max_size() const { return _alloc.max_size(); }
	bool 	  empty()	 const { return _tree.get_root() == _tree.get_sentinel(); }

	// // 23.3.1.2 element access:
	mapped_type& operator[](const key_type& k) {
		node *n = _findNode(k);
		if (n == _tree.get_sentinel())
			insert(value_type(k, mapped_type()));
		return _findNode(k)->_key.second;
	}

	// // modifiers:
	ft::pair<iterator, bool> insert(const value_type& val) {
		node *n = _findNode(val);
		if (n != _tree.get_sentinel())
			return ft::make_pair(iterator(n), false);
		
		n = new RBNode<value_type>(val, _tree.get_sentinel());
		_tree.insert(n);
		_size++;
		return ft::make_pair(iterator(n), true);
	}

	iterator insert(iterator position, const value_type& val) {
		(void) position;
		return insert(val).first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
		while (first != last) {
			insert(*first);
			first++;
		}
	}

	void erase(iterator position) {
		erase((*position).first);	
	}

	size_type erase(const key_type& k) {
		node *n = _findNode(k);
		if (n == _tree.get_sentinel())
			return 0;
		
		_tree.remove(n);
		if (size() == 0) {
			// std::cout << "Size is now 0, set root to sentinel\n"; 
			_tree.set_root(_tree.get_sentinel());
		}
		delete n;
		_size--;
		return 1;
	}

	void erase(iterator first, iterator last) {
		size_type size = 0;
		iterator it = first;

		while (it++ != last)
			size++;
		it = first;
		while (size) {
			first++;
			erase(it);
			it = first;
			size--;
		}
	}

	void swap(map<Key, T, Compare, Allocator>& rhs) { // TODO - refactor this shitty code
		value_compare tmp_comp = rhs._comp;
		allocator_type tmp_alloc = rhs._alloc;
		node * tmp_root = rhs._tree.get_root();
		node * tmp_nil = rhs._tree.get_sentinel();
		size_type tmp_size = rhs._size;

		rhs._comp = _comp;
		rhs._alloc = _alloc;
		rhs._size = _size;
		rhs._tree.set_root(_tree.get_root());
		rhs._tree.set_sentinel(_tree.get_sentinel());

		_comp = tmp_comp;
		_alloc = tmp_alloc;
		_size = tmp_size;
		_tree.set_root(tmp_root);
		_tree.set_sentinel(tmp_nil);
	}

	void clear() {
		while (_tree.get_root() != _tree.get_sentinel()) {
			erase(_tree.get_root()->_key.first);
		}
	}

	// // observers:
	key_compare		key_comp() const { return key_compare(); }
	value_compare	value_comp() const { return _comp; }
	allocator_type	get_allocator() const { return _alloc; }

	// // 23.3.1.3 map operations:
	iterator find(const key_type& k) { return iterator(_findNode(k)); }
	const_iterator find(const key_type& k) const { return const_iterator(_findNode(k)); }

	size_type count(const key_type& k) const {
		return (_findNode(k) != _tree.get_sentinel()) ? 1 : 0;
	}

	iterator lower_bound(const key_type& k) {
		value_type val(k, mapped_type());
		node * node = _tree.min();
		while (node != _tree.get_sentinel() && _comp(node->_key, val))
			node = node->successor();
		return iterator(node);
	}

	const_iterator lower_bound(const key_type& k) const {
		value_type val(k, mapped_type());
		node * node = _tree.min();
		while (node != _tree.get_sentinel() && _comp(node->_key, val))
			node = node->successor();
		return const_iterator(node);
	}

	iterator upper_bound(const key_type& k) {
		value_type val(k, mapped_type());
		node * node = _tree.min();
		while (node != _tree.get_sentinel() && !_comp(val, node->_key))
			node = node->successor();
		return iterator(node);
	}

	const_iterator upper_bound(const key_type& k) const {
		value_type val(k, mapped_type());
		node * node = _tree.min();
		while (node != _tree.get_sentinel() && !_comp(val, node->_key))
			node = node->successor();
		return const_iterator(node);
	}

	ft::pair<iterator,iterator> equal_range(const key_type& k) {
		ft::pair<iterator, iterator>	pair;

		pair.first = this->lower_bound(k);
		pair.second = this->upper_bound(k);
		return pair;
	}

	pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
		ft::pair<const_iterator, const_iterator>	pair;

		pair.first = this->lower_bound(k);
		pair.second = this->upper_bound(k);
		return pair;
	}

private:
	typedef RBNode<value_type> node;

	value_compare		_comp;
	allocator_type		_alloc;
	RBTree<value_type>	_tree;
	size_type			_size;

	node *_findNode(const key_type& k) const {
		value_type val(k, mapped_type());
		return _findNode(val);
	}

	node *_findNode(const value_type& val) const {
		node * node = _tree.get_root();
		bool comparison;

		while (node != _tree.get_sentinel()) {
			comparison = _comp(node->_key, val);
			if (!comparison && !_comp(val, node->_key))
				return node;
			else if (comparison)
				node = node->_right;
			else
				node = node->_left;
		}
		return node;
	}
};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	if (x.size() != y.size()) return false;

	typename ft::map<Key,T,Compare,Allocator>::const_iterator itx = x.begin();
	typename ft::map<Key,T,Compare,Allocator>::const_iterator ity = y.begin();

	while (itx != x.end()) {
		if (*itx != *ity) return false;
		itx++;
		ity++;
	}
	return true;
}

template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); // todo - use ft::lexicographical_compare
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	return !(x == y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	return y < x;
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	return !(x < y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y) {
	return !(y < x);
}

template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y) {
	x.swap(y);
}

}

#endif
