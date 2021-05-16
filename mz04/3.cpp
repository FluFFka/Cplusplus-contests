#include <vector>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> v1copy = v1;
    std::sort(v1copy.begin(), v1copy.end());
    auto last = std::unique(v1copy.begin(), v1copy.end());
    auto maxit = v1copy.begin(), minit = v1copy.begin();
    for (; maxit != last; ++maxit) {
        if (*maxit >= 0 && size_t(*maxit) >= v2.size()) {
            break;
        }
        if (*minit < 0) {
            ++minit;
        }
    }
    v1copy.erase(maxit, v1copy.end());
    int step{};
    bool end = false, was = false;
    auto it2 = v2.begin();
    for (auto it1 = minit, it2next = v2.begin(); 
            !end && it2next != v2.end() && it2 != v2.end();
            ++it2, ++it2next, ++step, was = false) {
        while (it1 != v1copy.end() && step == *it1) {
            was = true;
            ++it1;
            ++it2next;
            ++step;
            if (it2next == v2.end()) {
                end = true;
                break;
            }
            int temp = *it2;
            *it2 = *it2next;
            *it2next = temp;
        }
        if (end) {
            break;
        }
        if (!was) {
            int temp = *it2;
            *it2 = *it2next;
            *it2next = temp;
        }
    }
    if (v1.size() != 0) {
        v2.erase(it2, v2.end());
    }
}