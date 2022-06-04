#ifndef RB_NODE_HPP
#define RB_NODE_HPP

#include <cstddef>

template <class T>
class RBTree;

template <class T>
class RBNode {
public:
	RBNode(T key = 0): _key(key), _left(NULL), _right(NULL), _p(NULL) {};

	RBNode* search(T k) {
		RBNode* x = this;
		std::cout << "x:(" << *x << ") k:" << k << std::endl;
		while(x && x->_key != k) {
			if (k < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}
		return x;
	}

	static void inorder_walk(RBNode<T> *x) {
		if (x == NULL) return;

		inorder_walk(x->_left);
		std::cout << *x << std::endl;
		inorder_walk(x->_right);
	}

	friend std::ostream & operator<<(std::ostream & o, RBNode<T> const & rhs) {
		o << "&:" << &rhs << " key:" << rhs._key << " left:" << rhs._left << " right:" << rhs._right << " p:" << rhs._p;
		return o;
	}

    friend class RBTree<T>;

protected:
	T _key;
	RBNode *_left;
	RBNode *_right;
	RBNode *_p;
};



#endif