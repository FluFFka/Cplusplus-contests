template <typename T>
typename T::value_type process(T cont)
{
    typename T::value_type sum{};
    int num = 1;
    for (auto it = cont.rbegin(); it != cont.rend() && num < 6; ++it, ++num) {
        if (num == 1 || num == 3 || num == 5) {
            sum += *it;
        }
    }
    return sum;
}