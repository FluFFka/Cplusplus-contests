#include <iostream>
#include <string>

unsigned int to_num(unsigned char sym)
{
    if ('0' <= sym && '9' >= sym) {
        return sym - '0';
    }
    if ('a' <= sym && 'f' >= sym) {
        return sym - 'a' + 10;
    }
    return sym - 'A' + 10;
}

int main()
{
    std::string curr{};
    int state{};
    unsigned int num{};
    while (std::cin >> curr) {
        if (state == 0) {
            ++state;
            continue;
        }
        num = (num << 4) | to_num(curr[0]);
        num = (num << 4) | to_num(curr[1]);
        if (state % 4 == 0) {
            std::cout << num << std::endl;
        }
        if (state == 16) {
            state = 0;
        } else {
            ++state;
        }
    }
}