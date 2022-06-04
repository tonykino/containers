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

};

#endif
