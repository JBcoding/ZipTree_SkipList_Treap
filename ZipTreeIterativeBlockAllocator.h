//
// Created by Mads Bjoern on 2019-05-31.
//

#ifndef ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATOR_H
#define ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATOR_H

#include "ZipTreeIterative.h"
#include "ZipTreeBlockAllocator.h"

class ZipTreeIterativeBlockAllocator: public ZipTreeIterative, ZipTreeBlockAllocator {
    ZipTreeNode* (ZipTreeIterative::*insertReference)(ZipTreeNode *, ZipTreeNode *) = &ZipTreeIterative::insert;
};


#endif //ZIPTREES_ZIPTREEITERATIVEBLOCKALLOCATOR_H
