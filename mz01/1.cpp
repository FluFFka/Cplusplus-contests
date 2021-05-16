class Sum
{
    long long res;
public:
    Sum(int a, int b) : res(a + b) {}
    Sum(Sum a, int b) : res(a.get() + b) {}
    Sum(int a, Sum b) : res(a + b.get()) {}
    Sum(Sum a, Sum b) : res(a.get() + b.get()) {}
    int get() const
    {
        return res;
    }
};
