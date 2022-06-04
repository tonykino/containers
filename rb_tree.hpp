#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "rb_node.hpp"

template <class T>
class RBTree {
public:
    typedef RBNode<T> node;

    RBTree(): _root(NULL) {}
    void insert(node *z) {
        node *y = NULL;
        node *x = _root;

        while (x) {
            y = x;
            if (z->_key < x->_key)
                x = x->_left;
            else
                x = x->_right;
        }

        z->_p = y;
        if (y == NULL)
            _root = z;
        else if (z->_key < y->_key)
            y->_left = z;
        else
            y->_right = z;
    }

    node* search(T k) {
        return _root->search(k);
    }

    node* min() {
        return _root->min();
    }

    node* max() {
        return _root->max();
    }

    void print(void) {
        node::inorder_walk(_root);
    }


private:
    node* _root;

};

#endif
