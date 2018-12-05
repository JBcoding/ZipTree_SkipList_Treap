//
// Created by Mads Bjoern on 14/10/2018.
//

#include "SkipList.h"

SkipList::SkipList() {
    head = (SkipListNode*)malloc(sizeof(SkipListNode));
    head->next = (SkipListNode**)malloc(sizeof(SkipListNode*) * SKIP_LIST_MAX_HEIGHT);
    head->height = SKIP_LIST_MAX_HEIGHT;
    head->key = SMALLEST_KEY_VALUE;
    for (int i = 0; i < SKIP_LIST_MAX_HEIGHT; ++i) {
        head->next[i] = nullptr;
    }
}

void SkipList::insert(NODE_KEY value) {
    insert(value, randomHeight);
}

void SkipList::insert(NODE_KEY value, unsigned int height) {
    auto *x = (SkipListNode*)malloc(sizeof(SkipListNode));
    x->key = value;
    x->height = height;
    x->next = (SkipListNode**)malloc(sizeof(SkipListNode*) * x->height);
    insert(x, head, CURRENT_HEIGHT);
    size ++;
}

void SkipList::insert(SkipListNode *x, SkipListNode *node, unsigned int currentHeight) {
    if (node->next[currentHeight] == nullptr || COMPARE_KEY(node->next[currentHeight]->key, x->key) > 0) {
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

bool SkipList::contains(NODE_KEY key) {
    return find(key, head, CURRENT_HEIGHT) != nullptr;
}

SkipListNode *SkipList::find(NODE_KEY key, SkipListNode *node, int currentHeight) {
    if (currentHeight < 0) { return nullptr;}
    if (COMPARE_KEY(node->key, key) == 0) { return node;}
    if (node->next[currentHeight] == nullptr
    || COMPARE_KEY(node->next[currentHeight]->key, key) > 0) { return find(key, node, currentHeight - 1);}
    else { return find(key, node->next[currentHeight], currentHeight);}
}

bool SkipList::remove(NODE_KEY key) {
    SkipListNode *x = find(key, head, CURRENT_HEIGHT);
    if (x == nullptr) { return false;}
    remove(x, head, max(x->height, CURRENT_HEIGHT));
    size --;
    free(x);
    return true;
}

void SkipList::remove(SkipListNode *x, SkipListNode *node, int currentHeight) {
    if (currentHeight < 0 || COMPARE_KEY(node->key, x->key) > 0) { return;}
    if (node->next[currentHeight] == x) {
        node->next[currentHeight] = x->next[currentHeight];
        remove(x, node, currentHeight - 1);
    } else if (node->next[currentHeight] == nullptr || COMPARE_KEY(node->next[currentHeight]->key, x->key) > 0) {
        remove(x, node, currentHeight - 1);
    } else {
        remove(x, node->next[currentHeight], currentHeight);
    }
}



NODE_KEY *SkipList::getOrderedList() {
    NODE_KEY *list = (NODE_KEY *)malloc(sizeof(NODE_KEY) * size);
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
    NODE_KEY *bottomList = getOrderedList();
    for (int i = CURRENT_HEIGHT; i >= 0; --i) {
        SkipListNode *node = head->next[i];
        for (int j = 0; j < size; ++j) {
            if (node != nullptr && COMPARE_KEY(node->key, bottomList[j]) == 0) {
                printf(NODE_KEY_FORMAT_SPECIFIER, node->key); printf("\t");
                node = node->next[i];
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}
