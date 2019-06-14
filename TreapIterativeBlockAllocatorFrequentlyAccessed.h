//
// Created by Mads Bjoern on 2019-06-14.
//

#ifndef ZIPTREES_TREAPITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H
#define ZIPTREES_TREAPITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H

#include "TreapIterativeBlockAllocator.h"

class TreapIterativeBlockAllocatorFrequentlyAccessed: public TreapIterativeBlockAllocator {
protected:
    TreapNode* find(NODE_KEY key, TreapNode *node);
};


#endif //ZIPTREES_TREAPITERATIVEBLOCKALLOCATORFREQUENTLYACCESSED_H
