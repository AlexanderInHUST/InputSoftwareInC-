#include <iostream>
#include <vector>
#include <algorithm>
#include "model/PinyinNode.h"
#include "model/PinyinTrieTree.h"

void test(int mode) {

}

int main() {
    PinyinTrieTree *tireTree = new PinyinTrieTree;
    tireTree->initial();

    tireTree->chooseMode(SHUANGPIN_MODE);
    std::string src = "怕";
    std::string py = "pa";
    std::vector<char> v;
    v.insert(v.end(), src[0]);
    v.insert(v.end(), src[1]);
    v.insert(v.end(), src[2]);
    std::vector<CharacterPair *> *map = tireTree->getCharacters(py);
    std::vector<WordPair *> *wordMap = tireTree->chooseCharacter(v);
    for (auto x : *map) {
        std::string s1;
        s1.insert(s1.end(), x->self->at(0));
        s1.insert(s1.end(), x->self->at(1));
        s1.insert(s1.end(), x->self->at(2));
        std::cout << s1 << x->value << std::endl;
    }
    for (auto x : *wordMap) {
        std::cout << * x->self << std::endl;
    }
    tireTree->chooseWord(NOT_CHOOSE_S);

    tireTree->chooseMode(PINYIN_MODE);
    src = "怕";
    py = "pa";
    v.clear();
    v.insert(v.end(), src[0]);
    v.insert(v.end(), src[1]);
    v.insert(v.end(), src[2]);
    map = tireTree->getCharacters(py);
    wordMap = tireTree->chooseCharacter(v);
    for (auto x : *map) {
        std::string s1;
        s1.insert(s1.end(), x->self->at(0));
        s1.insert(s1.end(), x->self->at(1));
        s1.insert(s1.end(), x->self->at(2));
        std::cout << s1 << x->value << std::endl;
    }
    for (auto x : *wordMap) {
        std::cout << * x->self << std::endl;
    }
    tireTree->chooseWord(NOT_CHOOSE_S);

    tireTree->finishInput();
    delete (tireTree);
}