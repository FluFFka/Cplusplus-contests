#include <iostream>

bool B()
{
    char c;
    if (std::cin >> c) {
        if (c == 'd') {
            return true;
        }
        if (c == 'b') {
            return B();
        }
        return false;
    }
    return true;
}

bool A()
{
    char c;
    if (std::cin >> c) {
        if (c == 'e') {
            return true;
        }
        if (c == 'c') {
            bool ch = A();
            if (!ch) {
                return false;
            }
            if (std::cin >> c) {
                if (c != 'd') {
                    return false;
                }
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool S() {
    char c;
    if (std::cin >> c) {
        if (c == 'c') {
            return B();
        }
        if (c == 'a') {
            bool ch = A();
            if (!ch) {
                return false;
            }
            if (std::cin >> c) {
                if (c != 'b') {
                    return false;
                }
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}




int main()
{
    char c;
    if (S()) {
        if (std::cin >> c) {
            std::cout << 0 << std::endl;
            return 0;
        }
        std::cout << 1 << std::endl;
        return 0;
    }
    std::cout << 0 << std::endl;
    return 0;
}