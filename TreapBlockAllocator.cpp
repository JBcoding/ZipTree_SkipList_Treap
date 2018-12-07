//
// Created by Mads Bjoern on 2018-12-07.
//

#include "TreapBlockAllocator.h"

TreapBlockAllocator::TreapBlockAllocator() {
    currentBlockSize = 1;
    currentBlockIndex = 0;
    currentBlock = malloc(sizeof(TreapNode) * currentBlockSize);
}

void TreapBlockAllocator::insert(NODE_KEY value, unsigned int priority) {
    if (currentBlockSize <= currentBlockIndex) {
        currentBlockIndex = 0;
        currentBlockSize *= 2;
        currentBlock = malloc(sizeof(TreapNode) * currentBlockSize);
    }
    // pointer hack
    auto *x = (TreapNode *)((char*)currentBlock + sizeof(TreapNode) * currentBlockIndex ++);
    x->key = value;
    x->priority = priority;
    x->left = x->right = nullptr;
    root = Treap::insert(x, root);
    size ++;
}
