//
// Created by Mads Bjoern on 14/10/2018.
//

#include "SkipList.h"

SkipList::SkipList() {
    head = (SkipListNode*)malloc(sizeof(SkipListNode));
    head->next = (SkipListNode**)malloc(sizeof(SkipListNode*) * SKIP_LIST_MAX_HEIGHT);
    head->height = SKIP_LIST_MAX_HEIGHT;
    head->key = std::numeric_limits<long>::min();
    for (int i = 0; i < SKIP_LIST_MAX_HEIGHT; ++i) {
        head->next[i] = nullptr;
    }
}

void SkipList::insert(long value) {
    insert(value, randomHeight);
}

void SkipList::insert(long value, unsigned int height) {
    auto *x = (SkipListNode*)malloc(sizeof(SkipListNode));
    x->key = value;
    x->height = height;
    x->next = (SkipListNode**)malloc(sizeof(SkipListNode*) * x->height);
    insert(x, head, CURRENT_HEIGHT);
    size ++;
}

void SkipList::insert(SkipListNode *x, SkipListNode *node, unsigned int currentHeight) {
    if (node->next[currentHeight] == nullptr || compareKey(node->next[currentHeight]->key, x->key) > 0) {
        if (currentHeight == 0) {
            // insert here
            x->next[0] = node->next[0];
            node->next[0] = x;
        } else {
            // go down
            insert(x, node, currentHeight - 1);
            if (x->height > currentHeight) {
                x->next[currentHeight] = node->next[currentHeight];
                node->next[currentHeight] = x;
            }
        }
    } else {
        // go forward
        insert(x, node->next[currentHeight], currentHeight);
    }
}

bool SkipList::contains(long key) {
    return find(key, head, CURRENT_HEIGHT) != nullptr;
}

SkipListNode *SkipList::find(long key, SkipListNode *node, int currentHeight) {
    if (currentHeight < 0) { return nullptr;}
    if (compareKey(node->key, key) == 0) { return node;}
    if (node->next[currentHeight] == nullptr
    || compareKey(node->next[currentHeight]->key, key) > 0) { return find(key, node, currentHeight - 1);}
    else { return find(key, node->next[currentHeight], currentHeight);}
}

bool SkipList::remove(long key) {
    SkipListNode *x = find(key, head, CURRENT_HEIGHT);
    if (x == nullptr) { return false;}
    remove(x, head, max(x->height, CURRENT_HEIGHT));
    size --;
    free(x);
    return true;
}

void SkipList::remove(SkipListNode *x, SkipListNode *node, int currentHeight) {
    if (currentHeight < 0 || compareKey(node->key, x->key) > 0) { return;}
    if (node->next[currentHeight] == x) {
        node->next[currentHeight] = x->next[currentHeight];
        remove(x, node, currentHeight - 1);
    } else if (node->next[currentHeight] == nullptr || compareKey(node->next[currentHeight]->key, x->key) > 0) {
        remove(x, node, currentHeight - 1);
    } else {
        remove(x, node->next[currentHeight], currentHeight);
    }
}



long *SkipList::getOrderedList() {
    long *list = (long *)malloc(sizeof(long) * size);
    SkipListNode *node = head;
    for (int i = 0; i < size; ++i) {
        node = node->next[0];
        list[i] = node->key;
    }
    return list;
}

long SkipList::getSize() {
    return size;
}



void SkipList::print() {
    long *bottomList = getOrderedList();
    for (int i = CURRENT_HEIGHT; i >= 0; --i) {
        SkipListNode *node = head->next[i];
        for (int j = 0; j < size; ++j) {
            if (node != nullptr && node->key == bottomList[j]) {
                printf("%li\t", node->key);
                node = node->next[i];
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}
