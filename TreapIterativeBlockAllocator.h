//
// Created by Mads Bjoern on 2019-06-12.
//

#ifndef ZIPTREES_TREAPITERATIVEBLOCKALLOCATOR_H
#define ZIPTREES_TREAPITERATIVEBLOCKALLOCATOR_H

#include "TreapIterative.h"
#include "TreapBlockAllocator.h"

class TreapIterativeBlockAllocator: public TreapIterative, TreapBlockAllocator {
    TreapNode* (TreapIterative::*insertReference)(TreapNode *, TreapNode *) = &TreapIterative::insert;
};


#endif //ZIPTREES_TREAPITERATIVEBLOCKALLOCATOR_H
