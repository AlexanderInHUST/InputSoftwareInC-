#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<char>> vector;
    std::vector<char> s;
    s.insert(s.end(), '3');
    s.insert(s.end(), '4');
    s.insert(s.end(), '5');
    vector.insert(vector.end(), s);
    std::vector<char> s1;
    s1.insert(s1.end(), '3');
    s1.insert(s1.end(), '4');
    s1.insert(s1.end(), '5');
    std::vector<std::vector<char>>::iterator it = std::find(vector.begin(), vector.end(), s1);
    std::cout << (it == vector.end() - 1) << std::endl;
}