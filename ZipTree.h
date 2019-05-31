//
// Created by Mads Bjoern on 13/10/2018.
//

#ifndef ZIPTREES_ZIPTREE_H
#define ZIPTREES_ZIPTREE_H

#include <stdint.h>
#include <cstdint>

#include <cstdlib>
#include <cstdio>
#include "OrderedList.h"

#define randomRank static_cast<uint8_t>(__builtin_clz(rand())) - 1

typedef struct ZipTreeNode {
    NODE_KEY key;
    uint8_t rank;

    ZipTreeNode *left;
    ZipTreeNode *right;
} __attribute__ ((packed)) ZipTreeNode;

class ZipTree: public OrderedList {
public:
    ZipTree();

    void insert(NODE_KEY value) override;

    virtual void insert(NODE_KEY value, uint8_t rank);
    bool contains(NODE_KEY key) override;
    bool remove(NODE_KEY key) override;

    NODE_KEY* getOrderedList() override;
    long getSize() override;
    void print() override;

protected:
    ZipTreeNode *root;
    long size;

    virtual ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
    virtual ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);
    ZipTreeNode* remove(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* zip(ZipTreeNode *x, ZipTreeNode *y);

    unsigned long getOrderedList(ZipTreeNode *node, NODE_KEY* list, unsigned long index);
    void print(ZipTreeNode *node, int depth);
};


#endif //ZIPTREES_ZIPTREE_H
