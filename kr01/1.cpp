#include <iostream>
#include <vector>

void process(std::vector<uint64_t> &a, uint32_t s)
{
    size_t sz = a.size();
    a.insert(a.begin(), sz / s, 0);
    
    uint64_t curr_s = 0;
    uint64_t curr_i = 0;
    auto it2 = a.begin() + sz / s;
    auto it1 = a.begin();
    while (it2 != a.end()) {
        if (curr_i == s) {
            *it1 = curr_s;
            curr_i = 0;
        } else {
            *it1 = *it2;
            curr_s += *it2;
            ++it2;
            ++curr_i;
        }
        ++it1;
    }
    if (curr_i == s) {
        *it1 = curr_s;
    }
}
