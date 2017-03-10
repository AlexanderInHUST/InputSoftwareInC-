#include <iostream>

int main() {
    std::string s("我");
    char c[3];
    c[0] = s.at(0);
    c[1] = s.at(1);
    c[2] = s.at(2);
    s = std::string(c);
    std::cout << s << std::endl;
    return 0;
}