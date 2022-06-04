#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "rb_node.hpp"

template <class T>
class RBTree {
public:
    RBTree(): _root(NULL) {}
    void insert(RBNode<T> *z) {
        RBNode<T> *y = NULL;
        RBNode<T> *x = _root;

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

    
    void print(void) {
        RBNode<T>::inorder_walk(_root);
    }


private:
    RBNode<T>* _root;

};

#endif
