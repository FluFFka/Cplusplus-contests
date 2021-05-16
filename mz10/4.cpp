#include <iostream>

void M(int k)
{
    if (k == 0) {
        return;
    }
    std::cout << 'b';
    M(k - 2);
    std::cout << 'c';
}

void S(int k, int n)
{
    if (n == k) {
        while (n > 2) {
            n -= 2;
            S(k, n);
            std::cout << std::endl;
        }
        return;
    }
    if (n != 0) {
        std::cout << 'a';
        S(k - 2, n - 2);
        std::cout << 'd';
    } else {
        M(k);
    }
}

int main()
{
    int k;
    std::cin >> k;
    if (k % 2 != 0 || k < 4) {
        return 0;
    }
    S(k, k);
    return 0;
}