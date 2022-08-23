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

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<std::pair<const Key, T> > >
class map {

public:
	// types:   
	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef RBIterator<value_type> iterator;
	typedef const_pointer const_iterator; // todo : replace constpointer
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
	: _comp(comp), _alloc(alloc) {
	}
	
	// template <class InputIterator>
	// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());
	
	// map(const map<Key,T,Compare,Allocator>& x);
	
	// ~map();

	// map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);

	// // iterators:
	iterator begin() {
		return iterator(_tree.min());
	}

	// const_iterator begin() const;

	iterator end() {
		return iterator(_tree.get_sentinel());
	}

	// const_iterator end() const;
	
	reverse_iterator rbegin() {
		return reverse_iterator(_tree.max());
	}
	
	// const_reverse_iterator rbegin() const;
	
	reverse_iterator rend() {
		return reverse_iterator(_tree.get_sentinel());
	}
	
	// const_reverse_iterator rend() const;

	// // capacity:

	size_type size()	 const { return _tree.size(); }
	size_type max_size() const { return _alloc.max_size(); }
	bool 	  empty()	 const { return _tree.get_root() == _tree.get_sentinel(); }

	// // 23.3.1.2 element access:
	// T& operator[](const key_type& x);

	// // modifiers:
	std::pair<iterator, bool> insert(const value_type& val) {
		node *n = _findNode(val);
		if (n != _tree.get_sentinel())
			return std::make_pair(iterator(n), false);
		
		n = new RBNode<value_type>(val, _tree.get_sentinel());
		_tree.insert(n);
		return std::make_pair(iterator(n), true);
	}

	iterator insert(iterator position, const value_type& val) {
		(void) position;
		return insert(val).first;
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
		while (first != last) {
			insert(first);
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
		delete n;
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

	// void swap(map<Key,T,Compare,Allocator>&);
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
	iterator find(const key_type& k) {
		return iterator(_findNode(k));
	}

	// const_iterator find(const key_type& x) const;
	
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

	// const_iterator lower_bound(const key_type& x) const;

	iterator upper_bound(const key_type& k) {
		value_type val(k, mapped_type());
		node * node = _tree.min();
		while (node != _tree.get_sentinel() && !_comp(val, node->_key))
			node = node->successor();
		return iterator(node);
	}

	// const_iterator upper_bound(const key_type& x) const;
	
	std::pair<iterator,iterator> equal_range(const key_type& k) {
		std::pair<iterator, iterator>	pair;

		pair.first = this->lower_bound(k);
		pair.second = this->upper_bound(k);
		return pair;
	}

	// pair<const_iterator,const_iterator> equal_range(const key_type& x) const;


// private:
	typedef RBNode<value_type> node;

	value_compare		_comp;
	allocator_type		_alloc;
	RBTree<value_type>	_tree;

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

// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

// template <class Key, class T, class Compare, class Allocator>
// void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y) {
// 	x.swap(y);
// }

}
#endif