#include <iostream>
#include <vector>
#include <algorithm>
#include "model/PinyinNode.h"
#include "model/PinyinTireTree.h"

int main() {
//    std::string s = "复";
//    std::vector<char> v;
//    v.insert(v.end(), s[0]);
//    v.insert(v.end(), s[1]);
//    v.insert(v.end(), s[2]);
//    PinyinTireTree *tireTree = new PinyinTireTree;
//    tireTree->initial();
//    std::map<std::vector<char>, double, ValueComparator> *map = tireTree->getCharacters("fu");
//    std::map<std::string, double, WordsValueComparator> *wordMap = tireTree->chooseCharacter(v);
//    tireTree->chooseWord(NOT_CHOOSE_S);
//    std::map<std::string, double, WordsValueComparator>::iterator it;
//    for (it = wordMap->begin(); it != wordMap->end(); it++) {
//        std::cout << it->first << " " << it->second << std::endl;
//    }

    FILE *p = fopen("dic.txt", "r");
    char c;
    fscanf(p, "%c", &c);
    fclose(p);

}