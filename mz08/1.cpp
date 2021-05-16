#include <iostream>

int main()
{
    int m, n, r1, c1, r2, c2;
    std::cin >> m >> n;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        if (r1 < r2) {
            std::swap(r1, r2);
        }
        if (c1 < c2) {
            std::swap(c1, c2);
        }
        std::cout << std::min(r1 - r2, m - r1 + r2) + std::min(c1 - c2, n - c1 + c2) << std::endl;
    }
}