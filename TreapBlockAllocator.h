//
// Created by Mads Bjoern on 2018-12-07.
//

#ifndef ZIPTREES_TREAPBLOCKALLOCATOR_H
#define ZIPTREES_TREAPBLOCKALLOCATOR_H

#include <stdexcept>
#include "Treap.h"

class TreapBlockAllocator: virtual public Treap {
public:
    TreapBlockAllocator();

    void insert(NODE_KEY value, unsigned int priority);
    bool remove(NODE_KEY key) override { throw std::invalid_argument( "remove not implemented in BlockAllocator" ); }

protected:

    TreapNode* (Treap::*insertReference)(TreapNode *, TreapNode *) = &Treap::insert;

    void *currentBlock;
    long currentBlockSize;
    long currentBlockIndex;
};


#endif //ZIPTREES_TREAPBLOCKALLOCATOR_H
