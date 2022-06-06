#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "rb_node.hpp"
#include "type_traits.hpp"

template <class T>
class RBTree {
public:
	typedef RBNode<T> node;

	RBTree(): _nil(new node()) { _root = _nil; }
	~RBTree() { delete _nil; }

	void kinsert(T& k) {
		node *n = new node(k, _nil);
		insert(n);
	}

	void insert(node *z) {
		node *y = _nil;
		node *x = _root;

		while (x != _nil) {
			y = x;
			if (z->_key < x->_key)
				x = x->_left;
			else
				x = x->_right;
		}

		z->_p = y;
		if (y == _nil)
			_root = z;
		else if (z->_key < y->_key)
			y->_left = z;
		else
			y->_right = z;

		x->_left = _nil;
		z->_right = _nil;
		z->_c = red;
		insert_fixup(z);
	}

	node* search(T k) {
		return _root->search(k, _nil);
	}

	node* min() {
		return _root->min(_nil);
	}

	node* max() {
		return _root->max(_nil);
	}

	node* successor(node *n) {
		return n->successor(_nil);
	}

	node* predecessor(node *n) {
		return n->predecessor(_nil);
	}


	void print(void) {
		std::cout << "RBTree :" << std::endl;
		node::inorder_walk(_root, _nil);
		std::cout << "sentinel: " << _nil << std::endl << std::endl;
	}

	node* get_sentinel(void) {
		return _nil;
	}


private:
	node* _root;
	node* _nil;

	void insert_fixup(node *z) {
		while (z->_p->_c == red) {
			if (z->_p == z->_p->_p->_left) {
				node *y = z->_p->_p->_right;
				if (y->_c == red) {
					z->_p->_c = black;
					y->_c = black;
					z->_p->_p->_c = red;
					z = z->_p->_p;
				} else {
					if (z == z->_p->_right) {
						z = z->_p;
						left_rotate(z);
					}
					z->_p->_c = black;
					z->_p->_p->_c = red;
					right_rotate(z->_p->_p);
				}
			} else {
				node *y = z->_p->_p->_left;
				if (y->_c == red) {
					z->_p->_c = black;
					y->_c = black;
					z->_p->_p->_c = red;
					z = z->_p->_p;
				} else {
					if (z == z->_p->_left) {
						z = z->_p;
						right_rotate(z);
					}
					z->_p->_c = black;
					z->_p->_p->_c = red;
					left_rotate(z->_p->_p);
				}
			}
		}
		_root->_c = black;
	}

	void left_rotate(node *x) {
		node *y = x->_right;
		x->_right = y->_left;
		if (y->_left != _nil)
			y->_left->_p = x;

		y->_p = x->_p;
		if (x->_p == _nil)
			_root = y;
		else if (x == x->_p->_left)
			x->_p->_left = y;
		else
			x->_p->_right = y;
		y->_left = x;
		x->_p = y;
	}

	void right_rotate(node *x) {
		node *y = x->_left;
		x->_left = y->_right;
		if (y->_right != _nil)
			y->_right->_p = x;

		y->_p = x->_p;
		if (x->_p == _nil)
			_root = y;
		else if (x == x->_p->_right)
			x->_p->_right = y;
		else
			x->_p->_left = y;
		y->_right = x;
		x->_p = y;
	}
};

#endif
