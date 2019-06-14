//
// Created by Mads Bjoern on 08/11/2018.
//

#ifndef ZIPTREES_ORDEREDLIST_H
#define ZIPTREES_ORDEREDLIST_H

#include <cstring>

#define COMPARATOR_LONG 1
#define COMPARATOR_STRING 2
#define COMPARATOR_LONG_COUNT 3
#define COMPARATOR_STRING_COUNT 4

#if COMPARATOR == COMPARATOR_LONG
#define NODE_KEY long
#define NODE_KEY_FORMAT_SPECIFIER "%li"
#define SMALLEST_KEY_VALUE std::numeric_limits<long>::min()
#define EXTRA_VARIABLES ;
#define START_TEST clock_t t = clock();
#define END_TEST t = clock() - t; double time_taken = ((double)t)/CLOCKS_PER_SEC; printf("%lf\n", time_taken);
#define COMPARE_KEY(k1, k2) (k1 > k2) - (k1 < k2)
#define IMPORT_WORDS_AS_NUMBERS
#define LONG_TESTS
#elif COMPARATOR == COMPARATOR_STRING
#define NODE_KEY const char *
#define NODE_KEY_FORMAT_SPECIFIER "%s"
#define SMALLEST_KEY_VALUE ""
#define EXTRA_VARIABLES ;
#define START_TEST clock_t t = clock();
#define END_TEST t = clock() - t; double time_taken = ((double)t)/CLOCKS_PER_SEC; printf("%lf\n", time_taken);
#define COMPARE_KEY(k1, k2) strcmp(k1, k2)
#define IMPORT_WORDS
#define STRING_TESTS
#elif COMPARATOR == COMPARATOR_LONG_COUNT
#define NODE_KEY long
#define NODE_KEY_FORMAT_SPECIFIER "%li"
#define SMALLEST_KEY_VALUE std::numeric_limits<long>::min()
#define EXTRA_VARIABLES long comparisonsCounter = 0;
#define START_TEST list->comparisonsCounter = 0;
#define END_TEST printf("%li\n", list->comparisonsCounter);
#define FINAL_PRINT printf("%li\n", list->comparisonsCounter);
#define COMPARE_KEY(k1, k2) (k1 > k2) - (k1 < k2) + (++ comparisonsCounter - comparisonsCounter)
#define IMPORT_WORDS_AS_NUMBERS
#define LONG_TESTS
#elif COMPARATOR == COMPARATOR_STRING_COUNT
#define NODE_KEY const char *
#define NODE_KEY_FORMAT_SPECIFIER "%s"
#define SMALLEST_KEY_VALUE ""
#define EXTRA_VARIABLES long comparisonsCounter = 0;
#define START_TEST list->comparisonsCounter = 0;
#define END_TEST printf("%li\n", list->comparisonsCounter);
#define COMPARE_KEY(k1, k2) strcmp(k1, k2) + (++ comparisonsCounter - comparisonsCounter)
#define IMPORT_WORDS
#define STRING_TESTS
#endif



class OrderedList {
public:
    virtual void insert(NODE_KEY value) = 0;
    virtual bool contains(NODE_KEY key) = 0;
    virtual bool remove(NODE_KEY key) = 0;

    virtual NODE_KEY* getOrderedList() = 0;
    virtual long getSize() = 0;
    virtual void print() = 0;

    EXTRA_VARIABLES
};


#endif //ZIPTREES_ORDEREDLIST_H
