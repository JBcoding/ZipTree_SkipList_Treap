//
// Created by Mads Bjoern on 2019-06-13.
//

#ifndef ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H
#define ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H

#include "ZipTreeIterativeBlockAllocator.h"

class ZipTreeIterativeBlockAllocatorFrequentlyAccessed: public ZipTreeIterativeBlockAllocator {
protected:
    ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);
};


#endif //ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H
