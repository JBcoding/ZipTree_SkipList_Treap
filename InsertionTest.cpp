//
// Created by Mads Bjoern on 08/11/2018.
//

#include <iostream>

#include "OrderedList.h"
#include "ZipTree.h"
#include "SkipList.h"
#include "Treap.h"

void monotonicallyIncreasing(long type, long limit);
void zigzag(long type, long limit);

int main() {
    srand(0x2A); rand(); rand(); rand(); // to get it going :)


    long testType, testDataStructure, limit;
    scanf("%ld %ld %ld", &testType, &testDataStructure, &limit);

    if (testType == 1) {
        monotonicallyIncreasing(testDataStructure, limit);
    } else if (testType == 2) {
        zigzag(testDataStructure, limit);
    }
}

void monotonicallyIncreasing(long type, long limit) {
    OrderedList *list;
    if (type == 1) {
        list = new ZipTree();
    } else if (type == 2) {
        list = new SkipList();
    } else {
        list = new Treap();
    }

    for (long i = 0; i < limit; i ++) {
        list->insert(i);
    }
}

void zigzag(long type, long limit) {
    OrderedList *list;
    if (type == 1) {
        list = new ZipTree();
    } else if (type == 2) {
        list = new SkipList();
    } else {
        list = new Treap();
    }

    list->insert(0);
    for (long i = 1; i < limit / 2; i ++) {
        list->insert(i);
        list->insert(-i);
    }
}