//
// Created by Mads Bjoern on 15/10/2018.
//

#include "Treap.h"

void Treap::insert(NODE_KEY value) {
    insert(value, randomPriority);
}

void Treap::insert(NODE_KEY value, unsigned int priority) {
    auto *x = (TreapNode*)malloc(sizeof(TreapNode));
    x->key = value;
    x->priority = priority;
    x->left = x->right = nullptr;
    root = insert(x, root);
    size ++;
}

TreapNode* Treap::insert(TreapNode *x, TreapNode *node) {
    if (node == nullptr) { return x;}
    if (COMPARE_KEY(x->key, node->key) < 0) {
        node->left = insert(x, node->left);
        if (node->priority < node->left->priority) {
            // right tree rotation
            TreapNode *temp = node->left;
            node->left = node->left->right;
            temp->right = node;
            return temp;
        }
    } else {
        node->right = insert(x, node->right);
        if (node->priority < node->right->priority) {
            // left tree rotation
            TreapNode *temp = node->right;
            node->right = node->right->left;
            temp->left = node;
            return temp;
        }
    }
    return node;
}

bool Treap::contains(NODE_KEY key) {
    return find(key, root) != nullptr;
}

TreapNode *Treap::find(NODE_KEY key, TreapNode *node) {
    if (node == nullptr) { return nullptr;}
    if (COMPARE_KEY(node->key, key) == 0) { return node;}
    if (COMPARE_KEY(key, node->key) < 0) { return find(key, node->left);}
    else { return find(key, node->right);}
}

bool Treap::remove(NODE_KEY key) {
    TreapNode *x = find(key, root);
    if (x == nullptr) { return false;}
    root = remove(x, root);
    size --;
    free(x);
    return true;
}

TreapNode *Treap::remove(TreapNode *x, TreapNode *node) {
    if (x->left == nullptr && x->right == nullptr) {
        return removeLeaf(x, node);
    } else if (x->left == nullptr || x->right == nullptr) {
        return removeUnaryNode(x, node);
    } else {
        return removeBinaryNode(x, node);
    }
}

TreapNode *Treap::removeLeaf(TreapNode *x, TreapNode *node) {
    if (COMPARE_KEY(x->key, node->key) < 0) {
        if (node->left == x) {
            node->left = nullptr;
            return node;
        } else {
            node->left = removeLeaf(x, node->left);
        }
    } else {
        if (node->right == x) {
            node->right = nullptr;
            return node;
        } else {
            node->right = removeLeaf(x, node->right);
        }
    }
    return node;
}

TreapNode *Treap::removeUnaryNode(TreapNode *x, TreapNode *node) {
    if (COMPARE_KEY(x->key, node->key) < 0) {
        if (node->left == x) {
            node->left = getExistingChild(x);
            return node;
        } else {
            node->left = removeUnaryNode(x, node->left);
        }
    } else {
        if (node->right == x) {
            node->right = getExistingChild(x);
            return node;
        } else {
            node->right = removeUnaryNode(x, node->right);
        }
    }
    return node;
}

TreapNode *Treap::removeBinaryNode(TreapNode *x, TreapNode *node) {
    if (node == x) {
        TreapNode *successor = successorOfNodeWithARightChild(x);
        x = remove(successor, x);
        successor->left = x->left;
        successor->right = x->right;
        return successor;
    } else if (COMPARE_KEY(x->key, node->key) < 0) {
        node->left = removeBinaryNode(x, node->left);
        if (node->priority < node->left->priority) {
            // right tree rotation
            TreapNode *temp = node->left;
            node->left = node->left->right;
            temp->right = node;
            return temp;
        }
    } else {
        node->right = removeBinaryNode(x, node->right);
        if (node->priority < node->right->priority) {
            // left tree rotation
            TreapNode *temp = node->right;
            node->right = node->right->left;
            temp->left = node;
            return temp;
        }
    }
    return node;
}

TreapNode *Treap::successorOfNodeWithARightChild(TreapNode *x) {
    TreapNode *node = x->right;
    while (node->left != nullptr) {node = node->left;}
    return node;
}



NODE_KEY *Treap::getOrderedList() {
    NODE_KEY *list = (NODE_KEY *)malloc(sizeof(NODE_KEY) * size);
    getOrderedList(root, list, 0);
    return list;
}

unsigned long Treap::getOrderedList(TreapNode *node, NODE_KEY *list, unsigned long index) {
    if (node == nullptr) { return index;}
    index = getOrderedList(node->left, list, index);
    list[index++] = node->key;
    index = getOrderedList(node->right, list, index);
    return index;
}

long Treap::getSize() {
    return size;
}



void Treap::print() {
    print(root, 0);
}

void Treap::print(TreapNode *node, int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("\t");
    }
    if (node == nullptr) {
        printf("NULL\n");
        return;
    }
    printf("("); printf(NODE_KEY_FORMAT_SPECIFIER, node->key); printf(", %i)\n", node->priority);
    print(node->left, depth + 1);
    print(node->right, depth + 1);
}
