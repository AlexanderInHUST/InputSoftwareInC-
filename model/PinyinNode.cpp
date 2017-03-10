//
// Created by 唐艺峰 on 17/3/10.
//

#include <cstdio>
#include "PinyinNode.h"

PinyinNode::PinyinNode() {
    for (int i = 0; i < 26; i++) {
        children[i] = NULL;
    }
    addressStart = 0;
    length = 0;
    hasChild = false;
}