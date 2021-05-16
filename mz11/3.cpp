#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::map<int, std::string> > automat;
    std::string cur, n;
    char ch;
    while (1) {
        std::cin >> cur;
        if (cur == "END") {
            break;
        }
        std::cin >> ch >> n;
        automat[cur][ch] = n;
    }
    while (std::cin >> cur, cur != "END") {
        automat[cur][-1] = "y";
    }
    std::cin >> cur;
    std::string str;
    std::cin >> str;
    int num = 0;
    for (auto it = str.begin(); it != str.end(); ++it, ++num) {
        if (automat[cur].find(*it) == automat[cur].end()) {
            std::cout << 0 << std::endl << num << std::endl << cur << std::endl;
            return 0;
        } else {
            cur = automat[cur][*it];
        }
    }
    if (automat[cur][-1] != "y") {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
    std::cout << num << std::endl << cur << std::endl;
}