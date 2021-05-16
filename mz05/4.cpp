#include <algorithm>

template <typename It1, typename It2>
It2 myremove(It1 v1start1, It1 v1end1, It2 v2start, It2 v2end)
{
    std::vector<typename It1::value_type> v1(v1start1, v1end1);
    auto v1start = v1.begin();
    auto v1end = v1.end();
    int v1size = std::distance(v1start, v1end);
    std::sort(v1start, v1end);
    auto last = std::unique(v1start, v1end);
    auto maxit = v1start, minit = v1start;
    for (; maxit != last; ++maxit) {
        if (*maxit >= 0 && *maxit >= std::distance(v2start, v2end)) {
            break;
        }
        if (*minit < 0) {
            ++minit;
        }
    }
    v1end = maxit;
    int step{};
    bool end = false, was = false;
    auto it2 = v2start;
    for (auto it1 = minit, it2next = v2start; 
            !end && it2next != v2end && it2 != v2end;
            ++it2, ++it2next, ++step, was = false) {
        while (it1 != v1end && step == *it1) {
            was = true;
            ++it1;
            ++it2next;
            ++step;
            if (it2next == v2end) {
                end = true;
                break;
            }
            typename It2::value_type temp = std::move(*it2);
            *it2 = std::move(*it2next);
            *it2next = std::move(temp);
        }
        if (end) {
            break;
        }
        if (!was) {
            typename It2::value_type temp = std::move(*it2);
            *it2 = std::move(*it2next);
            *it2next = std::move(temp);
        }
    }
    if (v1size != 0) {
        return it2;
    }
    return v2end;
}