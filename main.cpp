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
    tireTree->finishInput();
    tireTree->close();
    delete(tireTree);
}