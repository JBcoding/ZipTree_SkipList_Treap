//
// Created by Mads Bjoern on 2019-01-03.
//

#ifndef ZIPTREES_ZIPTREEITERATIVE_H
#define ZIPTREES_ZIPTREEITERATIVE_H

#include "ZipTree.h"

class ZipTreeIterative: virtual public ZipTree {
protected:
    ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);
};


#endif //ZIPTREES_ZIPTREEITERATIVE_H
