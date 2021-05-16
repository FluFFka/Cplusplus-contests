#include <iostream>
#include <string>

int in_L(std::string s) 
{
    bool f = true;
    for (auto &el : s) {
        if (f) {
            if (el == '3' || el == '4') {
                continue;
            } else {
                if (el == '1' || el == '2') {
                    f = false;
                } else {
                    return 0;
                }
            }
        } else {
            if (el == '1' || el == '2') {
                continue;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    std::string s;
    while (std::cin >> s) {
        std::cout << in_L(s) << std::endl;
    }
}