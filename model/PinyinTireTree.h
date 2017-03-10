//
// Created by 唐艺峰 on 17/3/10.
//

#ifndef INPUTSOFTWAREC_PINYINTIRETREE_H
#define INPUTSOFTWAREC_PINYINTIRETREE_H

#include "PinyinNode.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstdio>

#define NOT_CHOOSE ' '
#define NOT_CHOOSE_S  " "

#define NO_WORDS -1
#define VALUE_DECAY_RATE 0.99999
#define VALUE_INCREASE_STEP 1

struct ValueComparator {
    std::vector<char> *curChars;
    std::vector<double> *curValue;

    bool operator()(const char &a, const double &b) const;
};

struct WordsValueComparator {
    std::vector<std::string> *curWords;
    std::vector<double> *curWordsValue;

    bool operator()(const std::string &a, const std::string &b) const;
};

class PinyinTireTree {

private:
    PinyinNode *root;
    std::ifstream config;
    FILE *dic;
    PinyinNode *curNode;
    std::vector<char> *curChars;
    std::vector<double> *curValue;
    std::vector<int> *curAddress;
    std::vector<std::string> *curWords;
    std::vector<double> *curWordsValue;
    std::vector<int> *curLengthOfWords;

    int wordStartAddress;
    bool isClear;
    ValueComparator *comparator;
    WordsValueComparator *wordsValueComparator;

    void addNode(PinyinNode *node, std::string key, std::string data);

    std::map<char, double, ValueComparator> getChars(PinyinNode *node, std::string key);

    std::map<std::string, double, WordsValueComparator> getWords(int pos);

    template<typename Out>
    void split(const std::string &s, char delim, Out result);

    std::vector<std::string> split(const std::string &s, char delim);

public:
    PinyinTireTree();

    void initial();

    std::map<char, double, ValueComparator> getCharacters(std::string key);

    std::map<std::string, double, WordsValueComparator> chooseCharacter(char ch);

    void chooseWord(std::string word);

};

#endif //INPUTSOFTWAREC_PINYINTIRETREE_H
