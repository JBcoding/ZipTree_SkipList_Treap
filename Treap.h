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
    long key;
    unsigned int priority;

    TreapNode *left;
    TreapNode *right;
} TreapNode;

class Treap: public OrderedList {
public:
    void insert(long value) override;
    void insert(long value, unsigned int priority);
    bool contains(long key) override;
    bool remove(long key) override;

    long* getOrderedList() override;
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

    unsigned long getOrderedList(TreapNode *node, long* list, unsigned long index);
    TreapNode* find(long key, TreapNode *node);
    void print(TreapNode *node, int depth);
};


#endif //ZIPTREES_TREAP_H
