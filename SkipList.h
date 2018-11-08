//
// Created by Mads Bjoern on 14/10/2018.
//

#ifndef ZIPTREES_SKIPLIST_H
#define ZIPTREES_SKIPLIST_H

#include <cstdlib>
#include <cstdio>
#include <limits>
#include "OrderedList.h"

#define SKIP_LIST_MAX_HEIGHT 32
#define CURRENT_HEIGHT (32 - __builtin_clz(size + 1))
#define randomHeight static_cast<unsigned int>(__builtin_clz(rand()) - 1) % CURRENT_HEIGHT + 1
#define max(a, b) (a > b) ? a : b

typedef struct SkipListNode {
    long key;
    unsigned int height;

    SkipListNode **next; // array of pointers
} SkipListNode;

class SkipList: public OrderedList {
public:
    SkipList();

    void insert(long value) override;
    void insert(long value, unsigned int height);
    bool contains(long key) override;
    bool remove(long key) override;

    long* getOrderedList() override;
    long getSize() override;
    void print() override;
private:
    SkipListNode *head;
    long size = 0;

    void insert(SkipListNode *x, SkipListNode *node, unsigned int currentHeight);
    SkipListNode* find(long key, SkipListNode *node, int currentHeight);
    void remove(SkipListNode *x, SkipListNode *node, int currentHeight);
};


#endif //ZIPTREES_SKIPLIST_H
