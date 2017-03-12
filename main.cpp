#include <iostream>
#include <vector>
#include <algorithm>
#include "model/PinyinNode.h"
#include "model/PinyinTireTree.h"

int main() {
    std::string s = "异";
    std::vector<char> v;
    v.insert(v.end(), s[0]);
    v.insert(v.end(), s[1]);
    v.insert(v.end(), s[2]);
    PinyinTireTree *tireTree = new PinyinTireTree;
    tireTree->initial();
    std::map<std::vector<char>, double, ValueComparator> *map = tireTree->getCharacters("y");
    std::map<std::string, double, WordsValueComparator> *wordMap = tireTree->chooseCharacter(v);
    tireTree->chooseWord(NOT_CHOOSE_S);
    std::map<std::vector<char>, double, ValueComparator>::iterator it;
    std::map<std::string, double, WordsValueComparator>::iterator wordIt;
    for (it = map->begin(); it != map->end(); it++) {
        std::string *test = new std::string;
        test->insert(test->end(), it->first.at(0));
        test->insert(test->end(), it->first.at(1));
        test->insert(test->end(), it->first.at(2));
        std::cout << *test << " " << it->second << std::endl;
    }
    for (wordIt = wordMap->begin(); wordIt != wordMap->end(); wordIt++) {
        std::cout << wordIt->first << " " << wordIt->second << std::endl;
    }

}