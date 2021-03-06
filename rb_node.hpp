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

	RBNode(T key = T(), node* sentinel = NULL): _key(key), _left(sentinel), _right(sentinel), _p(sentinel), _c(black) {};

	friend std::ostream & operator<<(std::ostream & o, node const & rhs) {
		o << "&:" << &rhs << " key:" << rhs._key << " left:" << rhs._left << " right:" << rhs._right << " p:" << rhs._p << " color:" << rhs._c;
		return o;
	}

    friend class RBTree<T>;

private:

	T _key;
	node *_left;
	node *_right;
	node *_p;
	Color _c;

	node* search(T k, node *sentinel) {
		node* x = this;
		while (x != sentinel && x->_key != k) {
			if (k < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}
		return x;
	}

	node* min(node *sentinel) {
		node *x = this;
		while (x->_left != sentinel)
			x = x->_left;
		return x;
	}

	node* max(node *sentinel) {
		node *x = this;
		while (x->_right != sentinel)
			x = x->_right;
		return x;
	}

	node* successor(node *sentinel) {
		node *x = this;
		if (x->_right != sentinel)
			return x->_right->min(sentinel);
		
		node* y = x->_p;
		while (y != sentinel && x == y->_right) {
			x = y;
			y = y->_p;
		}
		return y;
	}

	node* predecessor(node *sentinel) {
		node *x = this;
		if (x->_left != sentinel)
			return x->_left->max(sentinel);
		
		node* y = x->_p;
		while (y != sentinel && x == y->_left) {
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
};

#endif