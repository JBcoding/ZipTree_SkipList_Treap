//
// Created by Mads Bjoern on 08/11/2018.
//

#ifndef ZIPTREES_ORDEREDLIST_H
#define ZIPTREES_ORDEREDLIST_H


class OrderedList {
public:
    virtual void insert(long value) = 0;
    virtual bool contains(long key) = 0;
    virtual bool remove(long key) = 0;

    virtual long* getOrderedList() = 0;
    virtual long getSize() = 0;
    virtual void print() = 0;
};


#endif //ZIPTREES_ORDEREDLIST_H
