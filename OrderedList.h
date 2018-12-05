//
// Created by Mads Bjoern on 08/11/2018.
//

#ifndef ZIPTREES_ORDEREDLIST_H
#define ZIPTREES_ORDEREDLIST_H

#include <cstring>

#define comparatorLong 1
#define comparatorString 2
#define comparatorLongCount 3

#if comparator == comparatorLong
#define nodeKey long
#define nodeKeyFormatSpecifier "%li"
#define smallestKeyValue std::numeric_limits<long>::min()
#define extraVariables void;
#define finalPrint void;
#define compareKey(k1, k2) (k1 > k2) - (k1 < k2)
#define importWordsAsNumbers
#define longTests
#elif comparator == comparatorString
#define nodeKey const char *
#define nodeKeyFormatSpecifier "%s"
#define smallestKeyValue ""
#define extraVariables void;
#define finalPrint void;
#define compareKey(k1, k2) strcmp(k1, k2)
#define importWords
#define stringTests
#elif comparator == comparatorLongCount
#define nodeKey long
#define nodeKeyFormatSpecifier "%li"
#define smallestKeyValue std::numeric_limits<long>::min()
#define extraVariables long comparisonsCounter = 0;
#define finalPrint printf("%li\n", list->comparisonsCounter);
#define compareKey(k1, k2) (k1 > k2) - (k1 < k2) + (++ comparisonsCounter - comparisonsCounter)
#define importWordsAsNumbers
#define longTests
#endif



class OrderedList {
public:
    virtual void insert(nodeKey value) = 0;
    virtual bool contains(nodeKey key) = 0;
    virtual bool remove(nodeKey key) = 0;

    virtual nodeKey* getOrderedList() = 0;
    virtual long getSize() = 0;
    virtual void print() = 0;

    extraVariables
};


#endif //ZIPTREES_ORDEREDLIST_H
