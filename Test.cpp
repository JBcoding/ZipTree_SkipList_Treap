//
// Created by Mads Bjoern on 08/11/2018.
//

#include <iostream>

#include "OrderedList.h"
#include "ZipTree.h"
#include "SkipList.h"
#include "Treap.h"

#ifdef IMPORT_WORDS_AS_NUMBERS // enable by compiling with "-D IMPORT_WORDS_AS_NUMBERS"
#include "LargeConstants/WordsAsNumbers.h"
#endif

#ifdef IMPORT_WORDS // enable by compiling with "-D IMPORT_WORDS"
#include "LargeConstants/Words.h"
#endif


#define swap(l, i, j) if (i != j) {l[i] = l[i] ^ l[j]; l[j] = l[j] ^ l[i]; l[i] = l[i] ^ l[j];}

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
#ifdef LONG_TESTS
void insertMonotonicallyIncreasing(OrderedList *list, long limit) {
    for (long i = 0; i < limit; i ++) {
        list->insert(i);
    }
}

void insertZigzag(OrderedList *list, long limit) {
    list->insert(0);
    for (long i = 1; i < limit / 2; i ++) {
        list->insert(i);
        list->insert(-i);
    }
}

void insertWordsAsNumbers(OrderedList *list, long limit) {
    for (long i = 0; i < limit; i ++) {
        list->insert(wordsAsNumbersArray[i % lengthOfWordsAsNumbersArray]);
    }
}
#endif

#ifdef STRING_TESTS
void insertWords(OrderedList *list, long limit) {
    for (long i = 0; i < limit; i ++) {
        list->insert(wordsArray[i % lengthOfWordsArray]);
    }
}
#endif

#ifdef LONG_TESTS
void containsRandom(OrderedList *list, long limit) {
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

void containsSkewed(OrderedList *list, long limit) {
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(i);
    }

    shuffle(container, limit);

    for (long i = 0; i < limit; i ++) {
        list->contains(limit / container[i]);
    }
}

void containsWordsAsNumbers(OrderedList *list, long limit) {
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(wordsAsNumbersArray[i % lengthOfWordsAsNumbersArray]);
    }

    shuffle(container, limit);

    for (long i = 0; i < limit; i ++) {
        list->contains(wordsAsNumbersArray[i % lengthOfWordsAsNumbersArray]);
    }
}
#endif

#ifdef STRING_TESTS
void containsWords(OrderedList *list, long limit) {
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(wordsArray[i % lengthOfWordsArray]);
    }

    shuffle(container, limit);

    for (long i = 0; i < limit; i ++) {
        list->contains(wordsArray[i % lengthOfWordsArray]);
    }
}
#endif

int main() {
    srand(0x2A); rand(); rand(); rand(); // to get it going :)


    long testType, testDataStructure, limit;
    scanf("%ld %ld %ld", &testType, &testDataStructure, &limit);

    OrderedList *list = getStructure(testDataStructure);

    switch (testType) {
#ifdef LONG_TESTS
        case 1:
            insertMonotonicallyIncreasing(list, limit);
            break;
        case 2:
            insertZigzag(list, limit);
            break;
        case 3:
            insertWordsAsNumbers(list, limit);
            break;
#endif
#ifdef STRING_TESTS
        case 4:
            insertWords(list, limit);
            break;
#endif
#ifdef LONG_TESTS
        case 5:
            containsRandom(list, limit);
            break;
        case 6:
            containsSkewed(list, limit);
            break;
        case 7:
            containsWordsAsNumbers(list, limit);
            break;
#endif
#ifdef STRING_TESTS
        case 8:
            containsWords(list, limit);
            break;
#endif
        default:
            printf("Test not found, make sure you have compiled with the correct flags");
    }

    FINAL_PRINT
}