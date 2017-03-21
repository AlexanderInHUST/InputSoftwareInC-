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
#include <sstream>
#include "math.h"
#include "CharacterPair.h"
#include "WordPair.h"

#define NOT_CHOOSE ' '
#define NOT_CHOOSE_S  " "

#define NO_WORDS -1
#define VALUE_DECAY_RATE 0.999
#define VALUE_INCREASE_STEP 1
#define E 2.71828

class PinyinTrieTree {

private:
    PinyinNode *root;
    std::ifstream config;
    FILE *dic;
    PinyinNode *curNode;
    std::vector<std::vector<char>> *curChars;
    std::vector<double> *curValue;
    std::vector<int> *curAddress;
    std::vector<std::string> *curWords;
    std::vector<double> *curWordsValue;
    std::vector<int> *curLengthOfWords;

    int wordStartAddress;
    bool isClear;

    void addNode(PinyinNode *node, std::string key, std::string data);

    std::vector<CharacterPair *> * getChars(PinyinNode *node, std::string key);

    std::vector<WordPair *> * getWords(int pos);

    bool static characterSort(const CharacterPair *a, const CharacterPair *b);

    bool static wordSort(const WordPair *a, const WordPair *b);

    void clearTree(PinyinNode * node);

public:
    PinyinTrieTree();

    void initial();

    std::vector<CharacterPair *> * getCharacters(std::string key);

    std::vector<WordPair *> * chooseCharacter(std::vector<char> ch);

    void chooseWord(std::string word);

};

#endif //INPUTSOFTWAREC_PINYINTIRETREE_H
