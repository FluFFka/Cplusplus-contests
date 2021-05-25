#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::map<int, std::string> > automat;
    automat["S"]['a'] = "A";
    automat["S"]['b'] = "B";
    automat["A"]['a'] = "S";
    automat["A"]['b'] = "F";
    automat["A"]['c'] = "BC";
    automat["B"]['a'] = "S";
    automat["F"][-1] = "y";
    automat["BC"]['a'] = "SF";
    automat["BC"]['b'] = "B";
    automat["SF"]['a'] = "A";
    automat["SF"]['b'] = "B";
    automat["SF"][-1] = "y";

    char c;
    std::string str = "";
    while (std::cin >> c) {
        str += c;
    }
    std::string cur = "S";
    int num = 0;
    bool printed = false;
    for (auto it = str.begin(); it != str.end(); ++it, ++num) {
        if (automat[cur].find(*it) == automat[cur].end()) {
            std::cout << 0 << std::endl;
            printed = true;
            break;
        } else {
            cur = automat[cur][*it];
        }
    }
    if (!printed) {
        if (automat[cur][-1] != "y") {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }

}