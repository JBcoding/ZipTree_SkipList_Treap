//
// Created by Mads Bjoern on 2019-06-13.
//

#include "ZipTreeIterativeBlockAllocatorFrequentlyAccessed.h"

#ifdef ZIP_TREE_PARENT

ZipTreeNode *ZipTreeIterativeBlockAllocatorFrequentlyAccessed::find(NODE_KEY key, ZipTreeNode *node) {
    ZipTreeNode *previous = nullptr;
    while (node != nullptr) {
        node->parent = previous;
        if (COMPARE_KEY(node->key, key) == 0) {
            break;
        }
        previous = node;
        node = COMPARE_KEY(node->key, key) > 0 ? node->left : node->right;
    }
    if (node == nullptr) {
        return nullptr;
    }
    uint8_t newRank;
    randomRank(newRank)
    if (newRank <= node->rank) {
        return node;
    }
    node->rank = newRank;
    while (node->parent != nullptr && node->rank >= node->parent->rank) {
        if (node->rank == node->parent->rank) {
            if (COMPARE_KEY(node->parent->key, node->key) < 0) {
                break;
            }
        }
        ZipTreeNode *parent = node->parent;
        ZipTreeNode *parentParent = parent->parent;
        if (parent->left == node) {
            parent->left = node->right;
            node->right = parent;
        } else {
            parent->right = node->left;
            node->left = parent;
        }
        node->parent = parent->parent;
        parent->parent = node;
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

ZipTreeNode *ZipTreeIterativeBlockAllocatorFrequentlyAccessed::find(NODE_KEY key, ZipTreeNode *node) {return nullptr;}

#endif