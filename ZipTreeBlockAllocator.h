//
// Created by Mads Bjoern on 2018-12-07.
//

#ifndef ZIPTREES_ZIPTREEBLOCKALLOCATOR_H
#define ZIPTREES_ZIPTREEBLOCKALLOCATOR_H

#include <stdexcept>
#include "ZipTree.h"

class ZipTreeBlockAllocator: virtual public ZipTree {
public:
    ZipTreeBlockAllocator();

    void insert(NODE_KEY value, uint8_t rank);

    bool remove(NODE_KEY key) override { throw std::invalid_argument( "remove not implemented in BlockAllocator" ); }

protected:

    ZipTreeNode* (ZipTree::*insertReference)(ZipTreeNode *, ZipTreeNode *) = &ZipTree::insert;

    void *currentBlock;
    long currentBlockSize;
    long currentBlockIndex;
};


#endif //ZIPTREES_ZIPTREEBLOCKALLOCATOR_H
