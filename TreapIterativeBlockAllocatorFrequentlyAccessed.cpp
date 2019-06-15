//
// Created by Mads Bjoern on 2019-06-14.
//

#include "TreapIterativeBlockAllocatorFrequentlyAccessed.h"

#ifdef TREAP_ITERATIVE

TreapNode *TreapIterativeBlockAllocatorFrequentlyAccessed::find(NODE_KEY key, TreapNode *node) {
    TreapNode *previous = nullptr;
    while (node != nullptr) {
        node->parent = previous;
        if (COMPARE_KEY(node->key, key) == 0) {
            break;
        }
        previous = node;
        node = COMPARE_KEY(key, node->key) < 0 ? node->left : node->right;
    }
    if (node == nullptr) {
        return nullptr;
    }
    unsigned int newPriority = randomPriority;
    if (newPriority <= node->priority) {
        return node;
    }

    while (node->parent != nullptr && node->parent->priority < node->priority) {
        TreapNode *parent = node->parent;
        if (node->parent->left == node) {
            // right tree rotation
            parent->left = node->right;
            node->right = parent;
        } else {
            // left tree rotation
            parent->right = node->left;
            node->left = parent;
        }

        TreapNode *parentParent = parent->parent;
        parent->parent = node;
        node->parent = parentParent;

        if (parentParent != nullptr) {
            if (parentParent->left == parent) {
                parentParent->left = node;
            } else {
                parentParent->right = node;
            }
        }
    }

    if (node->parent == nullptr) {
        this->root = node;
    }
    return node;
}

#else

TreapNode *TreapIterativeBlockAllocatorFrequentlyAccessed::find(NODE_KEY key, TreapNode *node) {return nullptr;}

#endif