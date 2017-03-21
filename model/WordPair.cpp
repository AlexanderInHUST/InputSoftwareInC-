//
// Created by 唐艺峰 on 17/3/19.
//

#include "WordPair.h"

WordPair::WordPair(std::string * _self, double _value) {
    self = _self;
    value = _value;
}

void WordPair::clear() {
    delete(self);
}