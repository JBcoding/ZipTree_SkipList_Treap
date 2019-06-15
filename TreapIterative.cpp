//
// Created by Mads Bjoern on 2019-06-12.
//

#include "TreapIterative.h"

#ifdef TREAP_ITERATIVE

TreapNode *TreapIterative::insert(TreapNode *x, TreapNode *node) {
    if (node == nullptr) {
        return x;
    }

    TreapNode *previous = nullptr;
    TreapNode *current = node;
    while (current != nullptr) {
        current->parent = previous;
        previous = current;
        current = COMPARE_KEY(x->key, current->key) < 0 ? current->left : current->right;
    }

    if (COMPARE_KEY(x->key, previous->key) < 0) {
        previous->left = x;
    } else {
        previous->right = x;
    }
    x->parent = previous;

    current = x;
    while (current->parent != nullptr && current->parent->priority < current->priority) {
        TreapNode *parent = current->parent;
        if (current->parent->left == current) {
            // right tree rotation
            parent->left = current->right;
            current->right = parent;
        } else {
            // left tree rotation
            parent->right = current->left;
            current->left = parent;
        }

        TreapNode *parentParent = parent->parent;
        parent->parent = current;
        current->parent = parentParent;

        if (parentParent != nullptr) {
            if (parentParent->left == parent) {
                parentParent->left = current;
            } else {
                parentParent->right = current;
            }
        }
    }

    if (current->parent == nullptr) {
        return current;
    }

    return node;

}

TreapNode *TreapIterative::find(NODE_KEY key, TreapNode *node) {
    while (node != nullptr) {
        if (COMPARE_KEY(node->key, key) == 0) {
            return node;
        }
        node = COMPARE_KEY(key, node->key) < 0 ? node->left : node->right;
    }
    return nullptr;
}

#else

TreapNode *TreapIterative::insert(TreapNode *x, TreapNode *node) {return nullptr;}
TreapNode *TreapIterative::find(NODE_KEY key, TreapNode *node) {return nullptr;}

#endif