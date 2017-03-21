#include <iostream>
#include <vector>
#include <algorithm>
#include "model/PinyinNode.h"
#include "model/PinyinTrieTree.h"

int main() {
    std::string s = "江";
    std::vector<char> v;
    v.insert(v.end(), s[0]);
    v.insert(v.end(), s[1]);
    v.insert(v.end(), s[2]);
    PinyinTrieTree *tireTree = new PinyinTrieTree;
    tireTree->initial();
    std::vector<CharacterPair *> *map = tireTree->getCharacters("j");
    std::vector<WordPair *> *wordMap = tireTree->chooseCharacter(v);
    tireTree->chooseWord(NOT_CHOOSE_S);
    for(int i = 0; i < map->size(); i++) {
        std::string *test = new std::string;
        test->insert(test->end(), map->at(i)->self->at(0));
        test->insert(test->end(), map->at(i)->self->at(1));
        test->insert(test->end(), map->at(i)->self->at(2));
        std::cout << *test << " " << map->at(i)->value << std::endl;
    }
    for(int i = 0; i < wordMap->size(); i++) {
        std::cout << *(wordMap->at(i)->self) << " " << wordMap->at(i)->value << std::endl;
    }

    tireTree->finishInput();

    s = "奖";
    v.clear();
    v.insert(v.end(), s[0]);
    v.insert(v.end(), s[1]);
    v.insert(v.end(), s[2]);
    map = tireTree->getCharacters("j");
    wordMap = tireTree->chooseCharacter(v);
    tireTree->chooseWord(NOT_CHOOSE_S);
    for(int i = 0; i < map->size(); i++) {
        std::string *test = new std::string;
        test->insert(test->end(), map->at(i)->self->at(0));
        test->insert(test->end(), map->at(i)->self->at(1));
        test->insert(test->end(), map->at(i)->self->at(2));
        std::cout << *test << " " << map->at(i)->value << std::endl;
    }
    for(int i = 0; i < wordMap->size(); i++) {
        std::cout << *(wordMap->at(i)->self) << " " << wordMap->at(i)->value << std::endl;
    }

    tireTree->finishInput();
    tireTree->close();
}