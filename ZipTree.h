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
#define RANDOM_RANK_4_TO_5 5
#define RANDOM_RANK_5_TO_6 6
#define RANDOM_RANK_6_TO_7 7
#define RANDOM_RANK_7_TO_8 8

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
#elif RANDOM_RANK == RANDOM_RANK_4_TO_5
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1717986917?0:randomRankTemp>1374389533?1:randomRankTemp>1099511626?2:randomRankTemp>879609300?3:randomRankTemp>703687440?4:randomRankTemp>562949952?5:randomRankTemp>450359961?6:randomRankTemp>360287968?7:randomRankTemp>288230374?8:randomRankTemp>230584299?9:randomRankTemp>184467439?10:randomRankTemp>147573951?11:randomRankTemp>118059160?12:randomRankTemp>94447328?13:randomRankTemp>75557862?14:randomRankTemp>60446289?15:randomRankTemp>48357031?16:randomRankTemp>38685624?17:randomRankTemp>30948499?18:randomRankTemp>24758799?19:randomRankTemp>19807039?20:randomRankTemp>15845631?21:randomRankTemp>12676504?22:randomRankTemp>10141203?23:randomRankTemp>8112962?24:randomRankTemp>6490369?25:randomRankTemp>5192295?26:randomRankTemp>4153836?27:randomRankTemp>3323068?28:randomRankTemp>2658454?29:randomRankTemp>2126763?30:randomRankTemp>1701410?31:randomRankTemp>1361128?32:randomRankTemp>1088902?33:randomRankTemp>871121?34:randomRankTemp>696896?35:randomRankTemp>557516?36:randomRankTemp>446012?37:randomRankTemp>356809?38:randomRankTemp>285447?39:randomRankTemp>228357?40:randomRankTemp>182685?41:randomRankTemp>146148?42:randomRankTemp>116918?43:randomRankTemp>93534?44:randomRankTemp>74827?45:randomRankTemp>59861?46:randomRankTemp>47888?47:randomRankTemp>38310?48:randomRankTemp>30648?49:randomRankTemp>24518?50:randomRankTemp>19614?51:randomRankTemp>15691?52:randomRankTemp>12552?53:randomRankTemp>10041?54:randomRankTemp>8032?55:randomRankTemp>6425?56:randomRankTemp>5140?57:randomRankTemp>4112?58:randomRankTemp>3289?59:randomRankTemp>2631?60:randomRankTemp>2104?61:randomRankTemp>1683?62:randomRankTemp>1346?63:randomRankTemp>1076?64:randomRankTemp>860?65:randomRankTemp>688?66:randomRankTemp>550?67:randomRankTemp>440?68:randomRankTemp>352?69:randomRankTemp>281?70:randomRankTemp>224?71:randomRankTemp>179?72:randomRankTemp>143?73:randomRankTemp>114?74:randomRankTemp>91?75:randomRankTemp>72?76:randomRankTemp>57?77:randomRankTemp>45?78:randomRankTemp>36?79:randomRankTemp>28?80:randomRankTemp>22?81:randomRankTemp>17?82:randomRankTemp>13?83:randomRankTemp>10?84:randomRankTemp>8?85:randomRankTemp>6?86:randomRankTemp>4?87:randomRankTemp>3?88:randomRankTemp>2?89:randomRankTemp>1?90:91;
#elif RANDOM_RANK == RANDOM_RANK_5_TO_6
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1789569705?0:randomRankTemp>1491308087?1:randomRankTemp>1242756739?2:randomRankTemp>1035630615?3:randomRankTemp>863025512?4:randomRankTemp>719187926?5:randomRankTemp>599323271?6:randomRankTemp>499436059?7:randomRankTemp>416196715?8:randomRankTemp>346830595?9:randomRankTemp>289025495?10:randomRankTemp>240854579?11:randomRankTemp>200712149?12:randomRankTemp>167260124?13:randomRankTemp>139383436?14:randomRankTemp>116152863?15:randomRankTemp>96794052?16:randomRankTemp>80661710?17:randomRankTemp>67218091?18:randomRankTemp>56015075?19:randomRankTemp>46679229?20:randomRankTemp>38899357?21:randomRankTemp>32416130?22:randomRankTemp>27013441?23:randomRankTemp>22511200?24:randomRankTemp>18759333?25:randomRankTemp>15632777?26:randomRankTemp>13027314?27:randomRankTemp>10856095?28:randomRankTemp>9046745?29:randomRankTemp>7538954?30:randomRankTemp>6282461?31:randomRankTemp>5235384?32:randomRankTemp>4362820?33:randomRankTemp>3635683?34:randomRankTemp>3029735?35:randomRankTemp>2524779?36:randomRankTemp>2103982?37:randomRankTemp>1753318?38:randomRankTemp>1461098?39:randomRankTemp>1217581?40:randomRankTemp>1014650?41:randomRankTemp>845541?42:randomRankTemp>704617?43:randomRankTemp>587180?44:randomRankTemp>489316?45:randomRankTemp>407763?46:randomRankTemp>339802?47:randomRankTemp>283168?48:randomRankTemp>235973?49:randomRankTemp>196644?50:randomRankTemp>163870?51:randomRankTemp>136558?52:randomRankTemp>113798?53:randomRankTemp>94831?54:randomRankTemp>79025?55:randomRankTemp>65854?56:randomRankTemp>54878?57:randomRankTemp>45731?58:randomRankTemp>38109?59:randomRankTemp>31757?60:randomRankTemp>26464?61:randomRankTemp>22053?62:randomRankTemp>18377?63:randomRankTemp>15314?64:randomRankTemp>12761?65:randomRankTemp>10634?66:randomRankTemp>8861?67:randomRankTemp>7384?68:randomRankTemp>6153?69:randomRankTemp>5127?70:randomRankTemp>4272?71:randomRankTemp>3560?72:randomRankTemp>2966?73:randomRankTemp>2471?74:randomRankTemp>2059?75:randomRankTemp>1715?76:randomRankTemp>1429?77:randomRankTemp>1190?78:randomRankTemp>991?79:randomRankTemp>825?80:randomRankTemp>687?81:randomRankTemp>572?82:randomRankTemp>476?83:randomRankTemp>396?84:randomRankTemp>330?85:randomRankTemp>275?86:randomRankTemp>229?87:randomRankTemp>190?88:randomRankTemp>158?89:randomRankTemp>131?90:randomRankTemp>109?91:randomRankTemp>90?92:randomRankTemp>75?93:randomRankTemp>62?94:randomRankTemp>51?95:randomRankTemp>42?96:randomRankTemp>35?97:randomRankTemp>29?98:randomRankTemp>24?99:randomRankTemp>20?100:randomRankTemp>16?101:randomRankTemp>13?102:randomRankTemp>10?103:randomRankTemp>8?104:randomRankTemp>6?105:randomRankTemp>5?106:randomRankTemp>4?107:randomRankTemp>3?108:randomRankTemp>2?109:randomRankTemp>1?110:111;
#elif RANDOM_RANK == RANDOM_RANK_6_TO_7
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1840700268?0:randomRankTemp>1577743086?1:randomRankTemp>1352351216?2:randomRankTemp>1159158185?3:randomRankTemp>993564158?4:randomRankTemp>851626421?5:randomRankTemp>729965503?6:randomRankTemp>625684716?7:randomRankTemp>536301185?8:randomRankTemp>459686730?9:randomRankTemp>394017197?10:randomRankTemp>337729026?11:randomRankTemp>289482022?12:randomRankTemp>248127447?13:randomRankTemp>212680668?14:randomRankTemp>182297715?15:randomRankTemp>156255184?16:randomRankTemp>133933014?17:randomRankTemp>114799726?18:randomRankTemp>98399765?19:randomRankTemp>84342655?20:randomRankTemp>72293704?21:randomRankTemp>61966032?22:randomRankTemp>53113741?23:randomRankTemp>45526063?24:randomRankTemp>39022339?25:randomRankTemp>33447719?26:randomRankTemp>28669473?27:randomRankTemp>24573834?28:randomRankTemp>21063286?29:randomRankTemp>18054245?30:randomRankTemp>15475067?31:randomRankTemp>13264343?32:randomRankTemp>11369436?33:randomRankTemp>9745230?34:randomRankTemp>8353054?35:randomRankTemp>7159760?36:randomRankTemp>6136937?37:randomRankTemp>5260231?38:randomRankTemp>4508769?39:randomRankTemp>3864659?40:randomRankTemp>3312564?41:randomRankTemp>2839340?42:randomRankTemp>2433720?43:randomRankTemp>2086045?44:randomRankTemp>1788038?45:randomRankTemp>1532604?46:randomRankTemp>1313660?47:randomRankTemp>1125994?48:randomRankTemp>965137?49:randomRankTemp>827260?50:randomRankTemp>709080?51:randomRankTemp>607782?52:randomRankTemp>520956?53:randomRankTemp>446533?54:randomRankTemp>382742?55:randomRankTemp>328064?56:randomRankTemp>281197?57:randomRankTemp>241026?58:randomRankTemp>206593?59:randomRankTemp>177079?60:randomRankTemp>151782?61:randomRankTemp>130098?62:randomRankTemp>111512?63:randomRankTemp>95581?64:randomRankTemp>81926?65:randomRankTemp>70222?66:randomRankTemp>60190?67:randomRankTemp>51591?68:randomRankTemp>44220?69:randomRankTemp>37902?70:randomRankTemp>32487?71:randomRankTemp>27846?72:randomRankTemp>23868?73:randomRankTemp>20458?74:randomRankTemp>17535?75:randomRankTemp>15030?76:randomRankTemp>12882?77:randomRankTemp>11041?78:randomRankTemp>9463?79:randomRankTemp>8111?80:randomRankTemp>6952?81:randomRankTemp>5958?82:randomRankTemp>5106?83:randomRankTemp>4376?84:randomRankTemp>3750?85:randomRankTemp>3214?86:randomRankTemp>2754?87:randomRankTemp>2360?88:randomRankTemp>2022?89:randomRankTemp>1733?90:randomRankTemp>1485?91:randomRankTemp>1272?92:randomRankTemp>1090?93:randomRankTemp>934?94:randomRankTemp>800?95:randomRankTemp>685?96:randomRankTemp>587?97:randomRankTemp>503?98:randomRankTemp>431?99:randomRankTemp>369?100:randomRankTemp>316?101:randomRankTemp>270?102:randomRankTemp>231?103:randomRankTemp>198?104:randomRankTemp>169?105:randomRankTemp>144?106:randomRankTemp>123?107:randomRankTemp>105?108:randomRankTemp>90?109:randomRankTemp>77?110:randomRankTemp>66?111:randomRankTemp>56?112:randomRankTemp>48?113:randomRankTemp>41?114:randomRankTemp>35?115:randomRankTemp>30?116:randomRankTemp>25?117:randomRankTemp>21?118:randomRankTemp>18?119:randomRankTemp>15?120:randomRankTemp>12?121:randomRankTemp>10?122:randomRankTemp>8?123:randomRankTemp>6?124:randomRankTemp>5?125:randomRankTemp>4?126:randomRankTemp>3?127:randomRankTemp>2?128:randomRankTemp>1?129:130;
#elif RANDOM_RANK == RANDOM_RANK_7_TO_8
#define randomRank(v) int randomRankTemp = rand(); v = randomRankTemp>1879048191?0:randomRankTemp>1644167167?1:randomRankTemp>1438646271?2:randomRankTemp>1258815487?3:randomRankTemp>1101463551?4:randomRankTemp>963780607?5:randomRankTemp>843308031?6:randomRankTemp>737894527?7:randomRankTemp>645657711?8:randomRankTemp>564950497?9:randomRankTemp>494331684?10:randomRankTemp>432540223?11:randomRankTemp>378472695?12:randomRankTemp>331163608?13:randomRankTemp>289768157?14:randomRankTemp>253547137?15:randomRankTemp>221853744?16:randomRankTemp>194122026?17:randomRankTemp>169856772?18:randomRankTemp>148624675?19:randomRankTemp>130046590?20:randomRankTemp>113790766?21:randomRankTemp>99566920?22:randomRankTemp>87121055?23:randomRankTemp>76230923?24:randomRankTemp>66702057?25:randomRankTemp>58364299?26:randomRankTemp>51068761?27:randomRankTemp>44685165?28:randomRankTemp>39099519?29:randomRankTemp>34212079?30:randomRankTemp>29935569?31:randomRankTemp>26193622?32:randomRankTemp>22919419?33:randomRankTemp>20054491?34:randomRankTemp>17547679?35:randomRankTemp>15354219?36:randomRankTemp>13434941?37:randomRankTemp>11755573?38:randomRankTemp>10286126?39:randomRankTemp>9000360?40:randomRankTemp>7875315?41:randomRankTemp>6890900?42:randomRankTemp>6029537?43:randomRankTemp>5275844?44:randomRankTemp>4616363?45:randomRankTemp>4039317?46:randomRankTemp>3534402?47:randomRankTemp>3092601?48:randomRankTemp>2706025?49:randomRankTemp>2367771?50:randomRankTemp>2071799?51:randomRankTemp>1812824?52:randomRankTemp>1586221?53:randomRankTemp>1387943?54:randomRankTemp>1214450?55:randomRankTemp>1062643?56:randomRankTemp>929812?57:randomRankTemp>813585?58:randomRankTemp>711886?59:randomRankTemp>622900?60:randomRankTemp>545037?61:randomRankTemp>476907?62:randomRankTemp>417293?63:randomRankTemp>365131?64:randomRankTemp>319489?65:randomRankTemp>279552?66:randomRankTemp>244608?67:randomRankTemp>214032?68:randomRankTemp>187278?69:randomRankTemp>163868?70:randomRankTemp>143384?71:randomRankTemp>125461?72:randomRankTemp>109778?73:randomRankTemp>96055?74:randomRankTemp>84048?75:randomRankTemp>73542?76:randomRankTemp>64349?77:randomRankTemp>56305?78:randomRankTemp>49266?79:randomRankTemp>43107?80:randomRankTemp>37718?81:randomRankTemp>33003?82:randomRankTemp>28877?83:randomRankTemp>25267?84:randomRankTemp>22108?85:randomRankTemp>19344?86:randomRankTemp>16926?87:randomRankTemp>14810?88:randomRankTemp>12958?89:randomRankTemp>11338?90:randomRankTemp>9920?91:randomRankTemp>8680?92:randomRankTemp>7595?93:randomRankTemp>6645?94:randomRankTemp>5814?95:randomRankTemp>5087?96:randomRankTemp>4451?97:randomRankTemp>3894?98:randomRankTemp>3407?99:randomRankTemp>2981?100:randomRankTemp>2608?101:randomRankTemp>2282?102:randomRankTemp>1996?103:randomRankTemp>1746?104:randomRankTemp>1527?105:randomRankTemp>1336?106:randomRankTemp>1169?107:randomRankTemp>1022?108:randomRankTemp>894?109:randomRankTemp>782?110:randomRankTemp>684?111:randomRankTemp>598?112:randomRankTemp>523?113:randomRankTemp>457?114:randomRankTemp>399?115:randomRankTemp>349?116:randomRankTemp>305?117:randomRankTemp>266?118:randomRankTemp>232?119:randomRankTemp>203?120:randomRankTemp>177?121:randomRankTemp>154?122:randomRankTemp>134?123:randomRankTemp>117?124:randomRankTemp>102?125:randomRankTemp>89?126:randomRankTemp>77?127:randomRankTemp>67?128:randomRankTemp>58?129:randomRankTemp>50?130:randomRankTemp>43?131:randomRankTemp>37?132:randomRankTemp>32?133:randomRankTemp>28?134:randomRankTemp>24?135:randomRankTemp>21?136:randomRankTemp>18?137:randomRankTemp>15?138:randomRankTemp>13?139:randomRankTemp>11?140:randomRankTemp>9?141:randomRankTemp>7?142:randomRankTemp>6?143:randomRankTemp>5?144:randomRankTemp>4?145:randomRankTemp>3?146:randomRankTemp>2?147:randomRankTemp>1?148:149;
#endif

typedef struct ZipTreeNode {
    NODE_KEY key;
    uint8_t rank;

#ifdef ZIP_TREE_PARENT
    ZipTreeNode *parent;
#endif
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

    virtual ZipTreeNode* find(NODE_KEY key, ZipTreeNode *node);
    ZipTreeNode* remove(ZipTreeNode *x, ZipTreeNode *node);
    ZipTreeNode* zip(ZipTreeNode *x, ZipTreeNode *y);

    unsigned long getOrderedList(ZipTreeNode *node, NODE_KEY* list, unsigned long index);
    void print(ZipTreeNode *node, int depth);

public: // for function pointer purpose
    virtual ZipTreeNode* insert(ZipTreeNode *x, ZipTreeNode *node);
};


#endif //ZIPTREES_ZIPTREE_H
