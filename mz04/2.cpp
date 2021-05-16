#include <vector>

void process(std::vector<long long> &a, long long val)
{
    int expand{};
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (*it >= val) {
            ++expand;
        }
    }
    a.reserve(a.size() + expand);
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        if (*it >= val) {
            a.push_back(*it);
        }
    }
}