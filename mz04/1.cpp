#include <vector>

void process(const std::vector<unsigned long long> &a, std::vector<unsigned long long> &b, unsigned int step)
{
    auto it_b = b.rbegin();
    auto it_a = a.begin();
    for (; it_a < a.end() && it_b < b.rend(); it_a += step, ++it_b) {
        *it_b += *it_a;
    }
}
