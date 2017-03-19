//
// Created by 唐艺峰 on 17/3/19.
//

#ifndef INPUTSOFTWARECPP_CHARACTERPAIR_H
#define INPUTSOFTWARECPP_CHARACTERPAIR_H


#include <string>
#include <vector>

class CharacterPair {
public:
    std::vector<char> * self;
    double value;

    CharacterPair(std::vector<char> * _self, double _value);
};


#endif //INPUTSOFTWARECPP_CHARACTERPAIR_H
