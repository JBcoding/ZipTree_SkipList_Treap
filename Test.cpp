//
// Created by Mads Bjoern on 08/11/2018.
//

#include <iostream>

#include "OrderedList.h"
#include "ZipTree.h"
#include "SkipList.h"
#include "Treap.h"

#define swap(l, i, j) if (i != j) {l[i] = l[i] ^ l[j]; l[j] = l[j] ^ l[i]; l[i] = l[i] ^ l[j];}

void insertMonotonicallyIncreasing(long type, long limit);
void insertZigzag(long type, long limit);
void containsRandom(long type, long limit);
void containsRandom10Times(long type, long limit);

int main() {
    srand(0x2A); rand(); rand(); rand(); // to get it going :)


    long testType, testDataStructure, limit;
    scanf("%ld %ld %ld", &testType, &testDataStructure, &limit);

    if (testType == 1) {
        insertMonotonicallyIncreasing(testDataStructure, limit);
    } else if (testType == 2) {
        insertZigzag(testDataStructure, limit);
    } else if (testType == 3) {
        containsRandom(testDataStructure, limit);
    } else if (testType == 4) {
        containsRandom10Times(testDataStructure, limit);
    }
}

// Helper functions

OrderedList* getStructure(long type) {
    OrderedList *list;
    if (type == 1) {
        list = new ZipTree();
    } else if (type == 2) {
        list = new SkipList();
    } else {
        list = new Treap();
    }
    return list;
}

void shuffle(long *list, long size) {
    for (long i = 0; i < size; i ++) {
        int j = rand() % size;
        swap(list, i, j);
    }
}

// Tests

void insertMonotonicallyIncreasing(long type, long limit) {
    OrderedList *list = getStructure(type);

    for (long i = 0; i < limit; i ++) {
        list->insert(i);
    }
}

void insertZigzag(long type, long limit) {
    OrderedList *list = getStructure(type);

    list->insert(0);
    for (long i = 1; i < limit / 2; i ++) {
        list->insert(i);
        list->insert(-i);
    }
}

void containsRandom(long type, long limit) {
    OrderedList *list = getStructure(type);

    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(i);
    }

    shuffle(container, limit);

    for (long i = 0; i < limit; i ++) {
        list->contains(container[i]);
    }
}

void containsRandom10Times(long type, long limit) {
    OrderedList *list = getStructure(type);

    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(i);
    }

    shuffle(container, limit);

    for (int j = 0; j < 10; j ++) {
        for (long i = 0; i < limit; i++) {
            list->contains(container[i]);
        }
    }
}