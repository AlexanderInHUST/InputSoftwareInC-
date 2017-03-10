//
// Created by 唐艺峰 on 17/3/10.
//

#include <sstream>
#include "PinyinTireTree.h"

PinyinTireTree::PinyinTireTree() {
    config = std::ifstream("config.is", std::ios::in);
    dic = fopen("library.is", "rw");
    comparator = new ValueComparator;
    wordsValueComparator = new WordsValueComparator;
}

// Methods for tree

void PinyinTireTree::initial() {
    std::map<std::string, std::string> pinyinConfig;
    root = new PinyinNode;
    char line[32];
    std::string singleConfig;
    while (config.getline(line, sizeof(line))) {
        std::stringstream singleLine(line);
        std::string info[3];
        singleLine >> info[0];
        singleLine >> info[1];
        singleLine >> info[2];
        pinyinConfig.insert(std::make_pair(info[0], info[1] + " " + info[2]));
    }
    for (std::map<std::string, std::string>::iterator it = pinyinConfig.begin();
            it != pinyinConfig.end(); it++) {
        addNode(root, it->first, it->second);
    }
}

void PinyinTireTree::addNode(PinyinNode *node, std::string key, std::string data) {
    if (key.length() == 0) {
        std::vector<std::string> info = split(key, ' ');
        node->addressStart = std::stol(info.at(0));
        node->length = (short) std::stoi(info.at(1));
        node->hasChild = true;
    } else {
        char cur = key.at(0);
        if (node->children[cur - 'a'] == NULL) {
            node->children[cur - 'a'] = new PinyinNode;
        }
        addNode(node->children[cur - 'a'], key.substr(1, key.length() - 1), data);
    }
}

// Methods for character

std::map<char, double, ValueComparator> PinyinTireTree::getCharacters(std::string key) {
    curChars = new std::vector<char>;
    curValue = new std::vector<double>;
    curAddress = new std::vector<int>;
    curWords = new std::vector<std::string>;
    curWordsValue = new std::vector<double>;
    curLengthOfWords = new std::vector<int>;
    isClear = true;
    return getChars(root, key);
}

std::map<char, double, ValueComparator> PinyinTireTree::getChars(PinyinNode *node, std::string key) {
    if (key.length() == 0) {
        if (node->hasChild) {
            if (curNode == NULL)
                curNode = node;
            fseek(dic, node->addressStart, 0);
            std::map<char, double, ValueComparator> output;
            for (int i = 0; i < node->length; i++) {
                char singChar[3];
                fread(singChar, 1, 3, dic);
                std::string s(singChar);
            }
        }
    }
}

bool ValueComparator::operator()(const char &a, const double &b) const {
    std::vector<char>::iterator it1 = std::find(curChars->begin(), curChars->end(), a);
    std::vector<char>::iterator it2 = std::find(curChars->begin(), curChars->end(), b);
    int pos1 = (int) (it1 - curChars->begin());
    int pos2 = (int) (it2 - curChars->begin());
    return (curValue->at((unsigned long) pos1) <= curValue->at((unsigned long) pos2));
};

bool WordsValueComparator::operator()(const std::string &a, const std::string &b) const {
    std::vector<std::string>::iterator it1 = std::find(curWords->begin(), curWords->end(), a);
    std::vector<std::string>::iterator it2 = std::find(curWords->begin(), curWords->end(), b);
    int pos1 = (int) (it1 - curWords->begin());
    int pos2 = (int) (it2 - curWords->begin());
    return curWordsValue->at((unsigned long) pos1) <= curWordsValue->at((unsigned long) pos2);
};

template<typename Out>
void PinyinTireTree::split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> PinyinTireTree::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}