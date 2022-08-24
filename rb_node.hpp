#ifndef RB_NODE_HPP
#define RB_NODE_HPP

#include <cstddef>

enum Color { black, red };

template <class T>
class RBTree;

template <class T>
class RBNode {
public:
	typedef RBNode<T> node;

	T _key;
	node *_left;
	node *_right;
	node *_p;
	Color _c;
	node *_sentinel;
	node *_root;
	
	RBNode(const T& key = T(), node* sentinel = NULL, node *root = NULL)
	: _key(key), _left(sentinel), _right(sentinel), _p(sentinel),
	_c(black), _sentinel(sentinel), _root(root) {
		if (sentinel)
			_sentinel->_root = root;
	};

	node* search(T k) {
		node* x = this;
		while (x != _sentinel && x->_key != k) {
			if (k < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}
		return x;
	}

	node* min() {
		node *x = this;
		if (x == _sentinel)
			return _sentinel;

		while (x->_left != _sentinel)
			x = x->_left;
		return x;
	}

	node* max() {
		node *x = this;
		if (x == _sentinel)
			return _sentinel;
			
		while (x->_right != _sentinel)
			x = x->_right;
		return x;
	}

	node* successor() {
		node *x = this;
		if (_sentinel == NULL)
			return _root->min();

		if (x->_right != _sentinel)
			return x->_right->min();
		
		node* y = x->_p;
		while (y != _sentinel && x == y->_right) {
			x = y;
			y = y->_p;
		}
		return y;
	}

	node* predecessor() {
		node *x = this;
		if (_sentinel == NULL)
			return _root->max();

		if (x->_left != _sentinel)
			return x->_left->max();
		
		node* y = x->_p;
		while (y != _sentinel && x == y->_left) {
			x = y;
			y = y->_p;
		}
		return y;
	}

	static void inorder_walk(node *x, node *sentinel) {
		if (x == sentinel) return;

		inorder_walk(x->_left, sentinel);
		std::cout << *x << std::endl;
		inorder_walk(x->_right, sentinel);
	}

	friend std::ostream & operator<<(std::ostream & o, node const & rhs) {
		// TODO - faire en sorte qu'on puisse utiliser cet overload avec une pair as node
		o << "&:" << &rhs << " key:" << rhs._key.first << ":" << rhs._key.second << " left:" << rhs._left << " right:" << rhs._right << " p:" << rhs._p << " color:" << rhs._c;
		return o;
	}
};

#endif
