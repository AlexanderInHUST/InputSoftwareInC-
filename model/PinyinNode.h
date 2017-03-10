//
// Created by 唐艺峰 on 17/3/10.
//

#ifndef INPUTSOFTWAREC_PINYINNODE_H
#define INPUTSOFTWAREC_PINYINNODE_H


class PinyinNode {

public:
    long addressStart;
    short length;
    bool hasChild;
    PinyinNode * children[26];

    PinyinNode();
};


#endif //INPUTSOFTWAREC_PINYINNODE_H
