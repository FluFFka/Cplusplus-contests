template <typename T, typename Func>
T myfilter(T cont, Func filter)
{
    T res;
    for (auto el : cont) {
        if (filter(el)) {
            res.insert(res.end(), el);
        }
    }
    return res;
}