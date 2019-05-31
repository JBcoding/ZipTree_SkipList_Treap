//
// Created by Mads Bjoern on 2019-01-03.
//

#include "ZipTreeIterative.h"

ZipTreeNode *ZipTreeIterative::insert(ZipTreeNode *x, ZipTreeNode *node) {
    ZipTreeNode *current = node;
    ZipTreeNode *previous = nullptr;
    while (current != nullptr
            && (x->rank < current->rank
                || (x->rank == current->rank
                    && COMPARE_KEY(x->key, current->key) > 0))) {
        previous = current;
        current = (COMPARE_KEY(x->key, current->key) < 0) ? current->left : current->right;
    }
    if (current == node) { node = x; }
    else if (COMPARE_KEY(x->key, previous->key) < 0) { previous->left = x; }
    else { previous->right = x; }

    if (current == nullptr) { return node; }

    if (COMPARE_KEY(x->key, current->key) < 0) { x->right = current; }
    else {x->left = current; }

    previous = x;

    while (current != nullptr) {
        ZipTreeNode *fix = previous;
        if (COMPARE_KEY(current->key, x->key) < 0) {
            do {
                previous = current;
                current = current->right;
            } while (!(current == nullptr || COMPARE_KEY(current->key, x->key) > 0));
        } else {
            do {
                previous = current;
                current = current->left;
            } while (!(current == nullptr || COMPARE_KEY(current->key, x->key) < 0));
        }
        if (COMPARE_KEY(fix->key, x->key) > 0 || (fix == x && COMPARE_KEY(previous->key, x->key) > 0)) {
            fix->left = current;
        } else {
            fix->right = current;
        }
    }

    return node;
}

ZipTreeNode *ZipTreeIterative::find(NODE_KEY key, ZipTreeNode *node) {
    while (node != nullptr) {
        if (COMPARE_KEY(node->key, key) == 0) {
            return node;
        }
        node = COMPARE_KEY(node->key, key) > 0 ? node->left : node->right;
    }
    return nullptr;
}

/*
https://arxiv.org/pdf/1806.06726.pdf
 */