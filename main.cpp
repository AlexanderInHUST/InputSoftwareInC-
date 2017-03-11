#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s = "我";
    std::string ss;
    ss.insert(ss.end(), s.at(0));
    ss.insert(ss.end(), s.at(1));
    ss.insert(ss.end(), s.at(2));
    std::cout << (s == "我") << std::endl;
}