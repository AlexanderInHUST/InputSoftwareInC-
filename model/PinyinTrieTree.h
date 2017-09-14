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

#define PINYIN_MODE 1
#define SHUANGPIN_MODE 2

#define NO_WORDS -1
#define VALUE_DECAY_RATE 0.999
#define VALUE_INCREASE_STEP 1
#define E 2.71828



class PinyinTrieTree {

private:
    PinyinNode *root;
    PinyinNode *root_n;
    PinyinNode *root_d;
    std::ifstream config_n;
    std::ifstream config_d;
    FILE *dic;
    FILE *dic_n;
    FILE *dic_d;
    PinyinNode *curNode;
    std::vector<std::vector<char>> *curChars;
    std::vector<double> *curValue;
    std::vector<int> *curAddress;
    std::vector<std::string> *curWords;
    std::vector<double> *curWordsValue;
    std::vector<int> *curLengthOfWords;

    std::vector<CharacterPair *> * finalOutputChar;
    std::vector<WordPair *> * finalOutputWord;

    int wordStartAddress;
    bool isClear;

    void addNode(PinyinNode *node, std::string key, std::string data);

    void initialDetail(std::ifstream * config, PinyinNode ** root);

    std::vector<CharacterPair *> * getChars(PinyinNode *node, std::string key);

    std::vector<WordPair *> * getWords(int pos);

    bool static characterSort(const CharacterPair *a, const CharacterPair *b);

    bool static wordSort(const WordPair *a, const WordPair *b);

    void clearTree(PinyinNode * node);

    void clearCharVector(std::vector<CharacterPair *> * v);

    void clearWordVector(std::vector<WordPair *> * v);

public:
    PinyinTrieTree();

    void initial();

    void chooseMode(int state);

    std::vector<CharacterPair *> * getCharacters(std::string key);

    std::vector<WordPair *> * chooseCharacter(std::vector<char> ch);

    void chooseWord(std::string word);

    void finishInput();

    void close();

};

#endif //INPUTSOFTWAREC_PINYINTIRETREE_H
