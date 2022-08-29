#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "rb_node.hpp"

namespace ft {

template<class T> // , bool is_const>
struct RBIterator: public ft::iterator<std::bidirectional_iterator_tag, T> {
	typedef T																			value_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T *																			pointer;
	typedef T &																			reference;
	typedef std::bidirectional_iterator_tag												iterator_category;
	typedef RBNode<T>																	node;
	
	RBIterator(node * x = NULL) : _node(x) {}
	RBIterator(const RBIterator& mit) : _node(mit._node) {}
	virtual ~RBIterator() {};

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
		return _node == rhs._node;
	}

	bool operator!=(const RBIterator& rhs) const {
		return _node != rhs._node;
	}

	reference operator*() const {
		return _node->_key;
	}

	pointer operator->() const {
		return &(_node->_key);
	}

	RBNode<value_type> * _node;
};

template<class T>
struct RBConstIterator: public ft::iterator<std::bidirectional_iterator_tag, T> {
	typedef T																			value_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type	difference_type;
	typedef T const *																	pointer;
	typedef T const &																	reference;
	typedef std::bidirectional_iterator_tag												iterator_category;
	typedef RBNode<T>																	node;
	
	RBConstIterator(node * x = NULL): _node(x) {}
	RBConstIterator(const RBIterator<value_type>& mit): _node(mit._node) {}
	RBConstIterator(const RBConstIterator& mit): _node(mit._node) {}
	virtual ~RBConstIterator() {};

	RBConstIterator& operator=(const RBConstIterator& rhs) {
		_node = rhs._node;
		return *this;
	}

	RBConstIterator& operator++() {
		_node = _node->successor();
		return *this;
	}

	RBConstIterator operator++(int) {
		RBConstIterator tmp(*this);
		operator++();
		return tmp;
	}

	RBConstIterator& operator--() {
		_node = _node->predecessor();
		return *this;
	}

	RBConstIterator operator--(int) {
		RBConstIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const RBConstIterator& rhs) const {
		return _node == rhs._node;
	}

	bool operator!=(const RBConstIterator& rhs) const {
		return _node != rhs._node;
	}

	reference operator*() const {
		return _node->_key;
	}

	pointer operator->() const {
		return &(_node->_key);
	}

	RBNode<value_type> * _node;
};

}

#endif
