# InputSoftwareInCpp
## Class PinyinNode
* Description

    To save all data information of the Pinyin node and the structure information of tire tree.

## Class PinyinTireTree
* Description

    The main part of the program. Getting pinyin information in tire tree, looking up character or words in library.is or wordDic.txt, getting list of 
    characters or words and asking client to chooses one of them.

* Const

```cpp
#define VALUE_DECAY_RATE 1
// The decay rate of the value for the characters or words which are not chosen. We usually set it to 0.99999

#define VALUE_INCREASE_STEP 0
// The increase step of value for the chosen characters or words. We usually set it to 1

#define NOT_CHOOSE ' '
// The flag for chooseCharacter() in case that you don't want to choose anything

#define NOT_CHOOSE_S  " "
// The same with NOT_CHOOSE but it's made for chooseWord()
```

* Example

```cpp
int main() {
    std::string s = "异";
    std::vector<char> v;
    v.insert(v.end(), s[0]);
    v.insert(v.end(), s[1]);
    v.insert(v.end(), s[2]);
    // We use vector to store bytes of UTF-8

    PinyinTireTree *tireTree = new PinyinTireTree;
    tireTree->initial();
    // To load tire tree information
    
    std::map<std::vector<char>, double, ValueComparator> *map = tireTree->getCharacters("y");
    // To look up charaters with the pinyin "y"
    
    std::map<std::string, double, WordsValueComparator> *wordMap = tireTree->chooseCharacter(v);
    // To choose one of characters with vector form and fresh the value (the priority of order) of the characters
    
    tireTree->chooseWord(NOT_CHOOSE_S);
    // To choose one word
    
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
```

* Usage

```cpp
PinyinTireTree();
```

Please check your file name in constructor.

```cpp
void initial();
```

Nothing special.

```cpp
std::map<std::vector<char>, double, ValueComparator> * getCharacters(std::string key);
```

Send Pinyin as a string, e.g. "wa". Return a map containing all possible choice.

```cpp
std::map<std::string, double, WordsValueComparator> * chooseCharacter(std::vector<char> ch);
```

Send character appeared in the map getCharacters() returned in the form of vector. Return a map containing all possible choice. When you don't choose anything, send vector with the first element of NOT_CHOOSE. 

```cpp
void chooseWord(std::string word);
```

Send what you want to use appeared in the map chooseCharacter() returned. When you don't choose anything, send NOT_CHOOSE_S.

## File

### config.is

File for pinyin info.

### library.is

File for character info.

### wordsDic.txt

File for words info.

### other files

Others are made to get the suitable data.
