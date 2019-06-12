//
// Created by Mads Bjoern on 2019-01-03.
//

#ifndef ZIPTREES_ZIPTREEITERATIVE_H
#define ZIPTREES_ZIPTREEITERATIVE_H

#include "ZipTree.h"

class ZipTreeIterative: virtual public ZipTree {
protected:
    ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);

public: // for function pointer purpose
    ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
};


#endif //ZIPTREES_ZIPTREEITERATIVE_H
