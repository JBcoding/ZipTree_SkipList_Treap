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
    long key;
    uint8_t rank;

    ZipTreeNode *left;
    ZipTreeNode *right;
} ZipTreeNode;

class ZipTree: public OrderedList {
public:
    void insert(long value) override;
    void insert(long value, uint8_t rank);
    bool contains(long key) override;
    bool remove(long key) override;

    long* getOrderedList() override;
    long getSize() override;
    void print() override;
private:
    ZipTreeNode *root;
    long size = 0;

    ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* find(long key, ZipTreeNode *node);
    ZipTreeNode* remove(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* zip(ZipTreeNode *x, ZipTreeNode *y);

    unsigned long getOrderedList(ZipTreeNode *node, long* list, unsigned long index);
    void print(ZipTreeNode *node, int depth);
};


#endif //ZIPTREES_ZIPTREE_H
