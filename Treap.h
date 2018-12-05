//
// Created by Mads Bjoern on 15/10/2018.
//

#ifndef ZIPTREES_TREAP_H
#define ZIPTREES_TREAP_H

#include <cstdlib>
#include <cstdio>
#include "OrderedList.h"

#define randomPriority static_cast<unsigned int>(rand())
#define getExistingChild(x) (x->left == nullptr) ? x->right : x->left

typedef struct TreapNode {
    nodeKey key;
    unsigned int priority;

    TreapNode *left;
    TreapNode *right;
} TreapNode;

class Treap: public OrderedList {
public:
    void insert(nodeKey value) override;
    void insert(nodeKey value, unsigned int priority);
    bool contains(nodeKey key) override;
    bool remove(nodeKey key) override;

    nodeKey* getOrderedList() override;
    long getSize() override;
    void print() override;
private:
    TreapNode *root;
    long size;

    TreapNode* insert(TreapNode *x, TreapNode *node);
    TreapNode* remove(TreapNode *x, TreapNode *node);
    TreapNode* removeLeaf(TreapNode *x, TreapNode *node);
    TreapNode* removeUnaryNode(TreapNode *x, TreapNode *node);
    TreapNode* removeBinaryNode(TreapNode *x, TreapNode *node);
    TreapNode* successorOfNodeWithARightChild(TreapNode *x);

    unsigned long getOrderedList(TreapNode *node, nodeKey* list, unsigned long index);
    TreapNode* find(nodeKey key, TreapNode *node);
    void print(TreapNode *node, int depth);
};


#endif //ZIPTREES_TREAP_H
