//
// Created by Mads Bjoern on 13/10/2018.
//

#ifndef ZIPTREES_ZIPTREE_H
#define ZIPTREES_ZIPTREE_H

#include <stdint.h>
#include <cstdint>

#include <cstdlib>
#include <cstdio>
#include "OrderedList.h"

#define RANDOM_RANK_1_TO_2 0
#define RANDOM_RANK_1_TO_3 1
#define RANDOM_RANK_1_TO_4 2
#define RANDOM_RANK_2_TO_3 3
#define RANDOM_RANK_3_TO_4 4

#if RANDOM_RANK == RANDOM_RANK_1_TO_2
#define randomRank(v) v = static_cast<uint8_t>(__builtin_clz(rand())) - 1;
#elif RANDOM_RANK == RANDOM_RANK_1_TO_3
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>715827882?0:randomRankTemp>238609294?1:randomRankTemp>79536431?2:randomRankTemp>26512143?3:randomRankTemp>8837381?4:randomRankTemp>2945793?5:randomRankTemp>981931?6:randomRankTemp>327310?7:randomRankTemp>109103?8:randomRankTemp>36367?9:randomRankTemp>12122?10:randomRankTemp>4040?11:randomRankTemp>1346?12:randomRankTemp>448?13:randomRankTemp>149?14:randomRankTemp>49?15:randomRankTemp>16?16:randomRankTemp>5?17:randomRankTemp>1?18:19;
#elif RANDOM_RANK == RANDOM_RANK_1_TO_4
#define randomRank(v) v = (static_cast<uint8_t>(__builtin_clz(rand())) - 1) // 2
#elif RANDOM_RANK == RANDOM_RANK_2_TO_3
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1431655764?0:randomRankTemp>954437176?1:randomRankTemp>636291450?2:randomRankTemp>424194300?3:randomRankTemp>282796200?4:randomRankTemp>188530800?5:randomRankTemp>125687200?6:randomRankTemp>83791466?7:randomRankTemp>55860977?8:randomRankTemp>37240651?9:randomRankTemp>24827100?10:randomRankTemp>16551400?11:randomRankTemp>11034266?12:randomRankTemp>7356177?13:randomRankTemp>4904118?14:randomRankTemp>3269412?15:randomRankTemp>2179608?16:randomRankTemp>1453072?17:randomRankTemp>968714?18:randomRankTemp>645809?19:randomRankTemp>430539?20:randomRankTemp>287026?21:randomRankTemp>191350?22:randomRankTemp>127566?23:randomRankTemp>85044?24:randomRankTemp>56696?25:randomRankTemp>37797?26:randomRankTemp>25198?27:randomRankTemp>16798?28:randomRankTemp>11198?29:randomRankTemp>7465?30:randomRankTemp>4976?31:randomRankTemp>3317?32:randomRankTemp>2211?33:randomRankTemp>1474?34:randomRankTemp>982?35:randomRankTemp>654?36:randomRankTemp>436?37:randomRankTemp>290?38:randomRankTemp>193?39:randomRankTemp>128?40:randomRankTemp>85?41:randomRankTemp>56?42:randomRankTemp>37?43:randomRankTemp>24?44:randomRankTemp>16?45:randomRankTemp>10?46:randomRankTemp>6?47:randomRankTemp>4?48:randomRankTemp>2?49:randomRankTemp>1?50:51;
#elif RANDOM_RANK == RANDOM_RANK_3_TO_4
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1610612735?0:randomRankTemp>1207959551?1:randomRankTemp>905969663?2:randomRankTemp>679477247?3:randomRankTemp>509607935?4:randomRankTemp>382205951?5:randomRankTemp>286654463?6:randomRankTemp>214990847?7:randomRankTemp>161243135?8:randomRankTemp>120932351?9:randomRankTemp>90699263?10:randomRankTemp>68024447?11:randomRankTemp>51018335?12:randomRankTemp>38263751?13:randomRankTemp>28697813?14:randomRankTemp>21523359?15:randomRankTemp>16142519?16:randomRankTemp>12106889?17:randomRankTemp>9080166?18:randomRankTemp>6810124?19:randomRankTemp>5107593?20:randomRankTemp>3830694?21:randomRankTemp>2873020?22:randomRankTemp>2154765?23:randomRankTemp>1616073?24:randomRankTemp>1212054?25:randomRankTemp>909040?26:randomRankTemp>681780?27:randomRankTemp>511335?28:randomRankTemp>383501?29:randomRankTemp>287625?30:randomRankTemp>215718?31:randomRankTemp>161788?32:randomRankTemp>121341?33:randomRankTemp>91005?34:randomRankTemp>68253?35:randomRankTemp>51189?36:randomRankTemp>38391?37:randomRankTemp>28793?38:randomRankTemp>21594?39:randomRankTemp>16195?40:randomRankTemp>12146?41:randomRankTemp>9109?42:randomRankTemp>6831?43:randomRankTemp>5123?44:randomRankTemp>3842?45:randomRankTemp>2881?46:randomRankTemp>2160?47:randomRankTemp>1620?48:randomRankTemp>1215?49:randomRankTemp>911?50:randomRankTemp>683?51:randomRankTemp>512?52:randomRankTemp>384?53:randomRankTemp>288?54:randomRankTemp>216?55:randomRankTemp>162?56:randomRankTemp>121?57:randomRankTemp>90?58:randomRankTemp>67?59:randomRankTemp>50?60:randomRankTemp>37?61:randomRankTemp>27?62:randomRankTemp>20?63:randomRankTemp>15?64:randomRankTemp>11?65:randomRankTemp>8?66:randomRankTemp>6?67:randomRankTemp>4?68:randomRankTemp>3?69:randomRankTemp>2?70:randomRankTemp>1?71:72;
#endif

typedef struct ZipTreeNode {
    NODE_KEY key;
    uint8_t rank;

    ZipTreeNode *left;
    ZipTreeNode *right;
} __attribute__ ((packed)) ZipTreeNode;

class ZipTree: public OrderedList {
public:
    ZipTree();

    void insert(NODE_KEY value) override;

    virtual void insert(NODE_KEY value, uint8_t rank);
    bool contains(NODE_KEY key) override;
    bool remove(NODE_KEY key) override;

    NODE_KEY* getOrderedList() override;
    long getSize() override;
    void print() override;

protected:
    ZipTreeNode *root;
    long size;

    virtual ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
    virtual ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);
    ZipTreeNode* remove(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* zip(ZipTreeNode *x, ZipTreeNode *y);

    unsigned long getOrderedList(ZipTreeNode *node, NODE_KEY* list, unsigned long index);
    void print(ZipTreeNode *node, int depth);
};


#endif //ZIPTREES_ZIPTREE_H
