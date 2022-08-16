#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "rb_node.hpp"

namespace ft {

template<class T> // , bool is_const>
struct RBIterator: public ft::iterator<ft::bidirectional_iterator_tag, T> {
	typedef T																			value_type;
	typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T *																			pointer;
	typedef T &																			reference;
	typedef bidirectional_iterator_tag													iterator_category;
	typedef RBNode<T>																	node;
	
	RBIterator(node * x) : _node(x) {}
	RBIterator(const RBIterator& mit) : _node(mit._node) {}

	RBIterator& operator=(const RBIterator& rhs) {
		_node = rhs._node;
		return *this;
	}

	RBIterator& operator++() {
		_node = _node->successor();
		return *this;
	}

	RBIterator operator++(int) {
		RBIterator tmp(*this);
		operator++();
		return tmp;
	}

	RBIterator& operator--() {
		_node = _node->predecessor();
		return *this;
	}

	RBIterator operator--(int) {
		RBIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const RBIterator& rhs) const {
		return _node->_key == rhs._node->_key;
	}

	bool operator!=(const RBIterator& rhs) const {
		return _node->_key != rhs._node->_key;
	}

	node& operator*() {
		return *_node; // return _node->_key;
	}

private:
	RBNode<T> * _node;
};

}

#endif
