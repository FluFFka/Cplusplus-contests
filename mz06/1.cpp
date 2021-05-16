#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(10) << std::fixed;
    int w1, w2;
    std::cin >> w1 >> w2;
    int nuls{}, ones{};
    unsigned votes, votes1;
    while (std::cin >> votes) {
        votes1 = ~votes;
        while (votes) {
            ones += votes & 1;
            votes >>= 1;
        }
        while (votes1) {
            nuls += votes1 & 1;
            votes1 >>= 1;
        }
    }
    
    std::cout << -1 + 2 * double(ones - std::min(w2, ones)) / (ones + nuls) << " ";
    std::cout << -1 + 2 * double(ones + std::min(nuls, w1)) / (ones + nuls) << std::endl;
}