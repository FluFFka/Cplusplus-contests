#include <iostream>

int main()
{
    std::cin >> std::noskipws;
    char prev;
    char c;
    int num = 1;
    if (!std::cin.get(prev)) {
        return 0;
    }
    while (std::cin.get(c)) {
        if (c == prev) {
            num++;
        } else {
            if (num > 4 || prev == '#') {
                std::cout << "#" << prev << std::hex << num << "#";
            } else {
                for (int i = 0; i < num; ++i) {
                    std::cout << prev;
                }
            }
            num = 1;
            prev = c;
        }
        prev = c;
    }
    if (num > 4 || prev == '#') {
        std::cout << "#" << prev << std::hex << num << "#";
    } else {
        for (int i = 0; i < num; ++i) {
            std::cout << prev;
        }
    }
}