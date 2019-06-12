//
// Created by Mads Bjoern on 2019-06-12.
//

#ifndef ZIPTREES_TREAPITERATIVE_H
#define ZIPTREES_TREAPITERATIVE_H

#include "Treap.h"

class TreapIterative: virtual public Treap {
protected:
    TreapNode* insert(TreapNode *x, TreapNode *node);
    TreapNode* find(NODE_KEY key, TreapNode *node);
};


#endif //ZIPTREES_TREAPITERATIVE_H
