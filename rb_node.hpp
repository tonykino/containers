#ifndef RB_NODE_HPP
#define RB_NODE_HPP

#include <cstddef>

template <class T>
class RBTree;

template <class T>
class RBNode {
public:
	typedef RBNode<T> node;

	RBNode(T key = 0): _key(key), _left(NULL), _right(NULL), _p(NULL) {};

	node* search(T k) {
		node* x = this;
		// std::cout << "x:(" << *x << ") k:" << k << std::endl;
		while (x && x->_key != k) {
			if (k < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}
		return x;
	}

	node* min() {
		node *x = this;
		while (x->_left)
			x = x->_left;
		return x;
	}

	node* max() {
		node *x = this;
		while (x->_right)
			x = x->_right;
		return x;
	}

	node* successor() {
		node *x = this;
		if (x->_right)
			return x->_right->min();
		
		node* y = x->_p;
		while (y && x == y->_right) {
			x = y;
			y = y->_p;
		}
		return y;
	}

	node* predecessor() {
		node *x = this;
		if (x->_left)
			return x->_left->max();
		
		node* y = x->_p;
		while (y && x == y->_left) {
			x = y;
			y = y->_p;
		}
		return y;
	}

	static void inorder_walk(node *x) {
		if (x == NULL) return;

		inorder_walk(x->_left);
		std::cout << *x << std::endl;
		inorder_walk(x->_right);
	}

	friend std::ostream & operator<<(std::ostream & o, node const & rhs) {
		o << "&:" << &rhs << " key:" << rhs._key << " left:" << rhs._left << " right:" << rhs._right << " p:" << rhs._p;
		return o;
	}

    friend class RBTree<T>;

protected:
	T _key;
	node *_left;
	node *_right;
	node *_p;
};



#endif