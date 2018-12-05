//
// Created by Mads Bjoern on 13/10/2018.
//

#include "ZipTree.h"

void ZipTree::insert(NODE_KEY value) {
    insert(value, randomRank);
}

void ZipTree::insert(NODE_KEY value, uint8_t rank) {
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
        if (COMPARE_KEY(x->key, node->key) < 0) {
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

bool ZipTree::contains(NODE_KEY key) {
    return find(key, root) != nullptr;
}

ZipTreeNode *ZipTree::find(NODE_KEY key, ZipTreeNode *node) {
    if (node == nullptr) { return nullptr;}
    if (COMPARE_KEY(node->key, key) == 0) { return node;}
    if (COMPARE_KEY(node->key, key) > 0) { return find(key, node->left);}
    else { return find(key, node->right);}
}

bool ZipTree::remove(NODE_KEY key) {
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
        if (COMPARE_KEY(x->key, node->key) < 0) {
            if (COMPARE_KEY(x->key, node->left->key) == 0) {
                node->left = zip(node->left->left, node->left->right);
            } else {
                remove(x, node->left);
            }
        } else {
            if (COMPARE_KEY(x->key, node->right->key) == 0) {
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



NODE_KEY *ZipTree::getOrderedList() {
    NODE_KEY *list = (NODE_KEY *)malloc(sizeof(NODE_KEY) * size);
    getOrderedList(root, list, 0);
    return list;
}

unsigned long ZipTree::getOrderedList(ZipTreeNode *node, NODE_KEY *list, unsigned long index) {
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
    printf("("); printf(NODE_KEY_FORMAT_SPECIFIER, node->key); printf(", %i)\n", node->rank);
    print(node->left, depth + 1);
    print(node->right, depth + 1);
}
