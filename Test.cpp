//
// Created by Mads Bjoern on 08/11/2018.
//

#include <iostream>
#include <time.h>


#include "OrderedList.h"
#include "ZipTree.h"
#include "SkipList.h"
#include "Treap.h"
#include "ZipTreeBlockAllocator.h"
#include "TreapBlockAllocator.h"
#include "ZipTreeIterative.h"
#include "TreapIterative.h"
#include "ZipTreeIterativeBlockAllocator.h"
#include "TreapIterativeBlockAllocator.h"
#include "ZipTreeIterativeBlockAllocatorFrequentlyAccessed.h"
#include "TreapIterativeBlockAllocatorFrequentlyAccessed.h"

#ifdef IMPORT_WORDS_AS_NUMBERS
#include "LargeConstants/WordsAsNumbers.h"
#endif

#ifdef IMPORT_WORDS
#include "LargeConstants/Words.h"
#include "LargeConstants/Sentences.h"
#endif


#define swap(l, i, j) if (i != j) {l[i] = l[i] ^ l[j]; l[j] = l[j] ^ l[i]; l[i] = l[i] ^ l[j];}

// Helper functions

OrderedList* getStructure(long type, int limit) {
    OrderedList *list;
    if (type == 1) {
        list = new SkipList();
    } else if (type == 2) {
        list = new Treap();
    } else if (type == 3) {
        list = new TreapBlockAllocator();
    } else if (type == 4) {
        list = new TreapIterative();
    } else if (type == 5) {
        list = new TreapIterativeBlockAllocator();
    } else if (type == 6) {
        list = new TreapIterativeBlockAllocatorFrequentlyAccessed();
    } else if (type == 7) {
        list = new ZipTree();
    } else if (type == 8) {
        list = new ZipTreeBlockAllocator();
    } else if (type == 9) {
        list = new ZipTreeIterative();
    } else if (type == 10) {
        list = new ZipTreeIterativeBlockAllocator();
    } else if (type == 11) {
        list = new ZipTreeIterativeBlockAllocatorFrequentlyAccessed();
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
    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->insert(i);
    }
    END_TEST
}

void insertZigzag(OrderedList *list, long limit) {
    START_TEST
    list->insert(0);
    for (long i = 1; i < limit / 2; i ++) {
        list->insert(i);
        list->insert(-i);
    }
    END_TEST
}

void insertWordsAsNumbers(OrderedList *list, long limit) {
    long *container = getWordsAsNumbers(limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->insert(container[i]);
    }
    END_TEST
}
#endif

#ifdef STRING_TESTS
void insertWords(OrderedList *list, long limit) {
    char **words = getWords(limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->insert(words[i]);
    }
    END_TEST
}

void insertSentences(OrderedList *list, long limit) {
    char **sentences = getSentences(limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->insert(sentences[i]);
    }
    END_TEST
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

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->contains(container[i]);
    }
    END_TEST
}

void containsSkewed(OrderedList *list, long limit) {
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i + 1;
        list->insert(i);
    }

    shuffle(container, limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->contains(container[(limit - 1) / container[i]]);
    }
    END_TEST
}

void containsWordsAsNumbers(OrderedList *list, long limit) {
    long *container = getWordsAsNumbers(limit);

    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(container[i]);
    }

    shuffle(container, limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->contains(container[i]);
    }
    END_TEST
}
#endif

#ifdef STRING_TESTS
void containsWords(OrderedList *list, long limit) {
    char **words = getWords(limit);
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(words[i]);
    }

    shuffle(container, limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->contains(words[container[i]]);
    }
    END_TEST
}

void containsSentences(OrderedList *list, long limit) {
    char **sentences = getSentences(limit);
    long *container = (long*)malloc(sizeof(long) * limit);
    for (long i = 0; i < limit; i ++) {
        container[i] = i;
        list->insert(sentences[i]);
    }

    shuffle(container, limit);

    START_TEST
    for (long i = 0; i < limit; i ++) {
        list->contains(sentences[container[i]]);
    }
    END_TEST
}
#endif

int main() {
    srand(0x2A); rand(); rand(); rand(); // to get it going :)

    /*int y = 0;
    clock_t t = clock();
    for (int i = 0; i < 100000000; i ++) {
        randomRank(y);
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%lf\n", time_taken);
    return 0;
*/

    long testType, testDataStructure, limit;
    scanf("%ld %ld %ld", &testType, &testDataStructure, &limit);

    OrderedList *list = getStructure(testDataStructure, limit);

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
        case 5:
            insertSentences(list, limit);
            break;
#endif
#ifdef LONG_TESTS
        case 6:
            containsRandom(list, limit);
            break;
        case 7:
            containsSkewed(list, limit);
            break;
        case 8:
            containsWordsAsNumbers(list, limit);
            break;
#endif
#ifdef STRING_TESTS
        case 9:
            containsWords(list, limit);
            break;
        case 10:
            containsSentences(list, limit);
            break;
#endif
        default:
            printf("Test not found, make sure you have compiled with the correct flags");
    }

}