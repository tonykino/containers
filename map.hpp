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
	// std::pair<iterator, bool> insert(const value_type& x) {

	// }
	// iterator insert(iterator position, const value_type& x);

	// template <class InputIterator>
	// void insert(InputIterator first, InputIterator last);
	
	// void erase(iterator position);
	// size_type erase(const key_type& x);
	// void erase(iterator first, iterator last);
	// void swap(map<Key,T,Compare,Allocator>&);
	// void clear();
	
	// // observers:
	key_compare		key_comp() const {
		return key_compare();
	}

	value_compare		value_comp() const {
		return this->_comp;
	}

	// // 23.3.1.3 map operations:
	iterator find(const key_type& k) {
		value_type x(k, mapped_type());
		node * node = _tree.get_root();
		bool comparison;

		while (node != _tree.get_sentinel()) {
			comparison = _comp(node->_key, x);
			if (!comparison && !_comp(x, node->_key)) {
				return iterator(node);
			}
			else if (comparison)
				node = node->_right;
			else
				node = node->_left;
		}
		return iterator(node);
	}
	
	// const_iterator find(const key_type& x) const;
	// size_type count(const key_type& x) const;
	// iterator lower_bound(const key_type& x);
	// const_iterator lower_bound(const key_type& x) const;
	// iterator upper_bound(const key_type& x);
	// const_iterator upper_bound(const key_type& x) const;
	
	// pair<iterator,iterator> equal_range(const key_type& x);
	// pair<const_iterator,const_iterator> equal_range(const key_type& x) const;

	// allocator_type get_allocator() const;

// private:
	typedef RBNode<value_type> node;

	value_compare		_comp;
	allocator_type		_alloc;
	RBTree<value_type>	_tree;
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