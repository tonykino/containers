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

	void remove(node *z) {
		node *y = z;
		node *x = NULL;
		Color y_color = y->_c;
		if (z->_left == _nil) {
			x = z->_right;
			_transplant(z, z->_right);
		} else if (z->_right == _nil) {
			x = z->_left;
			_transplant(z, z->_left);
		} else {
			y = z->_right->min(_nil);
			y_color = y->_c;
			x = y->_right;
			if (x->_p == z) {
				x->_p = y;
			} else {
				_transplant(y, y->_right);
				y->_right = z->_right;
				y->_right->_p = y;
			}
			_transplant(z, y);
			y->_left = z->_left;
			y->_left->_p = y;
			y->_c = z->_c;
		}
		if (y_color == black)
			_remove_fixup(x);
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
		print("", _root, false);
		std::cout << std::endl;
	}

	void print(const std::string &prefix, const node *node, bool is_left)
	{
		if (node != _root)
			std::cout << prefix << (is_left ? "├──" : "└──" );
		if (node == _nil)
			std::cout << "NIL:B" << std::endl;
		else
			std::cout << node->_key << ":" << (node->_c == black ? "B" : "R") << std::endl;

		if( node != _nil )
		{
			print( prefix + (is_left ? "│   " : "    "), node->_left, true);
			print( prefix + (is_left ? "│   " : "    "), node->_right, false);
		}
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

	void _transplant(node *x, node *y) {
		if (x->_p == _nil)
			_root = y;
		else if (x == x->_p->_left)
			x->_p->_left = y;
		else
			x->_p->_right = y;
		y->_p = x->_p;
	}

	void _remove_fixup(node *x) {
		while (x != _root && x->_c == black) {
			if (x == x->_p->_left) {
				node *w = x->_p->_right;
				if (w->_c == red) {
					w->_c = black;
					x->_p->_c = red;
					left_rotate(x->_p);
					w = x->_p->_right;
				}
				if (w->_left->_c == black && w->_right->_c == black) {
					w->_c = red;
					x = x->_p;
				} else {
					if (w->_right->_c == black) {
						w->_left->_c = black;
						w->_c = red;
						right_rotate(w);
						w = x->_p->_right;
					}
					w->_c = x->_p->_c;
					x->_p->_c = black;
					w->_right->_c = black;
					left_rotate(x->_p);
					x = _root;
				}
			} else {
				node *w = x->_p->_left;
				if (w->_c == red) {
					w->_c = black;
					x->_p->_c = red;
					right_rotate(x->_p);
					w = x->_p->_left;
				}
				if (w->_right->_c == black && w->_left->_c == black) {
					w->_c = red;
					x = x->_p;
				} else {
					if (w->_left->_c == black) {
						w->_right->_c = black;
						w->_c = red;
						left_rotate(w);
						w = x->_p->_left;
					}
					w->_c = x->_p->_c;
					x->_p->_c = black;
					w->_left->_c = black;
					right_rotate(x->_p);
					x = _root;
				}
			}
		}
		x->_c = black;
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
