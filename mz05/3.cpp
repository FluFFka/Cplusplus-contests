#include <vector>
#include <functional>

template <typename It, typename Func>
void myapply(It start, It end, Func f)
{
    for (auto it = start; it != end; ++it) {
        f(*it);
    }
}

template <typename It, typename Func>
auto myfilter2(It start, It end, Func f)
{
    std::vector<std::reference_wrapper<typename It::value_type>> refs;
    for (auto it = start; it != end; ++it) {
        if (f(*it)) {
            std::reference_wrapper<typename It::value_type> ref(*it);
            refs.push_back(ref);
        }
    }
    return refs;
}

template <typename It, typename Func>
void myapply(It *start, It *end, Func f)
{
    for (auto it = start; it != end; ++it) {
        f(*it);
    }
}

template <typename It, typename Func>
auto myfilter2(It *start, It *end, Func f)
{
    std::vector<std::reference_wrapper<It>> refs;
    for (auto it = start; it != end; ++it) {
        if (f(*it)) {
            std::reference_wrapper<It> ref(*it);
            refs.push_back(ref);
        }
    }
    return refs;
}