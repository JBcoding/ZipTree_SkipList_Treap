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
    NODE_KEY key;
    unsigned int priority;

#ifdef TREAP_ITERATIVE
    TreapNode *parent;
#endif
    TreapNode *left;
    TreapNode *right;
} TreapNode;

class Treap: public OrderedList {
public:
    Treap();

    void insert(NODE_KEY value) override;
    virtual void insert(NODE_KEY value, unsigned int priority);
    bool contains(NODE_KEY key) override;
    bool remove(NODE_KEY key) override;

    NODE_KEY* getOrderedList() override;
    long getSize() override;
    void print() override;

protected:
    TreapNode *root;
    long size;

    virtual TreapNode* insert(TreapNode *x, TreapNode *node);
    TreapNode* remove(TreapNode *x, TreapNode *node);
    TreapNode* removeLeaf(TreapNode *x, TreapNode *node);
    TreapNode* removeUnaryNode(TreapNode *x, TreapNode *node);
    TreapNode* removeBinaryNode(TreapNode *x, TreapNode *node);
    TreapNode* successorOfNodeWithARightChild(TreapNode *x);

    unsigned long getOrderedList(TreapNode *node, NODE_KEY* list, unsigned long index);
    virtual TreapNode* find(NODE_KEY key, TreapNode *node);
    void print(TreapNode *node, int depth);
};


#endif //ZIPTREES_TREAP_H
