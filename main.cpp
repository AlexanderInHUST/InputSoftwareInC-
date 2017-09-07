#include <iostream>
#include <vector>
#include <algorithm>
#include "model/PinyinNode.h"
#include "model/PinyinTrieTree.h"

int main() {
    PinyinTrieTree *tireTree = new PinyinTrieTree;
    tireTree->initial();
    tireTree->chooseMode(PINYIN_MODE);
    std::string src = "哈";
    std::string py = "ha";

//    for(int i = 0; i < py.length(); i++) {
//        std::string s;
//        s.insert(s.end(), src[i * 3]);
//        s.insert(s.end(), src[i * 3 + 1]);
//        s.insert(s.end(), src[i * 3 + 2]);
//        std::string p;
//        p.insert(p.end(), py[i]);
//        std::vector<char> v;
//        v.insert(v.end(), s[0]);
//        v.insert(v.end(), s[1]);
//        v.insert(v.end(), s[2]);
//        std::vector<CharacterPair *> *map = tireTree->getCharacters(p);
//        std::vector<WordPair *> *wordMap = tireTree->chooseCharacter(v);
//        for(auto x : *map) {
//            std::string s1;
//            s1.insert(s1.end(), x->self->at(0));
//            s1.insert(s1.end(), x->self->at(1));
//            s1.insert(s1.end(), x->self->at(2));
//            std::cout << s1 << std::endl;
//        }
//        for(auto x : *wordMap) {
//            std::cout << x->self << std::endl;
//        }
//        tireTree->chooseWord(NOT_CHOOSE_S);
//        tireTree->finishInput();
//    }
//    tireTree->close();

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
        std::cout << s1 << std::endl;
    }
    for (auto x : *wordMap) {
        std::cout << * x->self << std::endl;
    }
    tireTree->chooseWord(NOT_CHOOSE_S);
    tireTree->finishInput();
    delete (tireTree);
}