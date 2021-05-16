#include <iostream>

int is_L(std::string &s) {
    int num1 = 0, num2 = 0;
    bool e = false, e2 = false;
    int st = 0;
    for (auto &el : s) {
        if (st == 0) {
            if (el == 'a') {
                e = true;
                num1++;
            } else {
                st = 1;
            }
        }
        if (st == 1) {
            if (el == '0') {
                e2 = true;
                num2++;
            } else {
                st = 2;
            }
        }
        if (st == 2) {
            if (el == 'b') {
                num1--;
            } else {
                st = 3;
            }
        }
        if (st == 3) {
            if (el == '1') {
                num2--;
            } else {
                st = 4;
            }
        }
        if (st == 4) {
            return 0;
        }
    }
    if (!e || !e2 || num1 != 0 || num2 != 0) {
        return 0;
    }
    return 1;
}

int main()
{
    std::string s;
    while (std::cin >> s) {
        std::cout << is_L(s) << std::endl;
    }
}