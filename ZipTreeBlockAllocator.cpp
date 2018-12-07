//
// Created by Mads Bjoern on 2018-12-07.
//

#include "ZipTreeBlockAllocator.h"

ZipTreeBlockAllocator::ZipTreeBlockAllocator() {
    currentBlockSize = 1;
    currentBlockIndex = 0;
    currentBlock = malloc(sizeof(ZipTreeNode) * currentBlockSize);
}

void ZipTreeBlockAllocator::insert(NODE_KEY value, uint8_t rank) {
    if (currentBlockSize <= currentBlockIndex) {
        currentBlockIndex = 0;
        currentBlockSize *= 2;
        currentBlock = malloc(sizeof(ZipTreeNode) * currentBlockSize);
    }
    // pointer hack
    auto *x = (ZipTreeNode *)((char*)currentBlock + sizeof(ZipTreeNode) * currentBlockIndex ++);
    x->key = value;
    x->rank = rank;
    x->left = x->right = nullptr;
    root = ZipTree::insert(x, root);
    size ++;
}

