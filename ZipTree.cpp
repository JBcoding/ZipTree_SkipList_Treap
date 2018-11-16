//
// Created by Mads Bjoern on 13/10/2018.
//

#include "ZipTree.h"

void ZipTree::insert(long value) {
    insert(value, randomRank);
}

void ZipTree::insert(long value, uint8_t rank) {
    auto *x = (ZipTreeNode*)malloc(sizeof(ZipTreeNode));
    x->key = value;
    x->rank = rank;
    x->left = x->right = nullptr;
    root = insert(x, root);
    size ++;
}

ZipTreeNode *ZipTree::insert(ZipTreeNode *x, ZipTreeNode *node) {
    if (node == nullptr) {
        node = x;
    } else {
        if (x->key < node->key) {
            if (insert(x, node->left) == x) {
                if (x->rank < node->rank) {
                    node->left = x;
                } else {
                    node->left = x->right;
                    x->right = node;
                    return x;
                }
            }
        } else {
            if (insert(x, node->right) == x) {
                if (x->rank <= node->rank) {
                    node->right = x;
                } else {
                    node->right = x->left;
                    x->left = node;
                    return x;
                }
            }
        }
    }
    return node;
}

bool ZipTree::contains(long key) {
    return find(key, root) != nullptr;
}

ZipTreeNode *ZipTree::find(long key, ZipTreeNode *node) {
    if (node == nullptr) { return nullptr;}
    if (node->key == key) { return node;}
    if (node->key > key) { return find(key, node->left);}
    else { return find(key, node->right);}
}

bool ZipTree::remove(long key) {
    ZipTreeNode *x = find(key, root);
    if (x == nullptr) { return false;}
    root = remove(x, root);
    size --;
    free(x);
    return true;
}

ZipTreeNode * ZipTree::remove(ZipTreeNode *x, ZipTreeNode *node) {
    if (x == node) {
        return zip(node->left, node->right);
    } else {
        if (x->key < node->key) {
            if (x->key == node->left->key) {
                node->left = zip(node->left->left, node->left->right);
            } else {
                remove(x, node->left);
            }
        } else {
            if (x->key == node->right->key) {
                node->right = zip(node->right->left, node->right->right);
            } else {
                remove(x, node->right);
            }
        }
    }
    return node;
}

ZipTreeNode *ZipTree::zip(ZipTreeNode *x, ZipTreeNode *y) {
    if (x == nullptr) { return y;}
    if (y == nullptr) { return x;}
    if (x->rank < y->rank) {
        y->left = zip(x, y->left);
        return y;
    } else {
        x->right = zip(x->right, y);
        return x;
    }
}



long *ZipTree::getOrderedList() {
    long *list = (long *)malloc(sizeof(long) * size);
    getOrderedList(root, list, 0);
    return list;
}

unsigned long ZipTree::getOrderedList(ZipTreeNode *node, long *list, unsigned long index) {
    if (node == nullptr) { return index;}
    index = getOrderedList(node->left, list, index);
    list[index++] = node->key;
    index = getOrderedList(node->right, list, index);
    return index;
}

long ZipTree::getSize() {
    return size;
}



void ZipTree::print() {
    print(root, 0);
}

void ZipTree::print(ZipTreeNode *node, int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("\t");
    }
    if (node == nullptr) {
        printf("NULL\n");
        return;
    }
    printf("(%li, %i)\n", node->key, node->rank);
    print(node->left, depth + 1);
    print(node->right, depth + 1);
}
