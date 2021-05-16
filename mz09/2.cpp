#include <iostream>

//Ackermann function

class Result
{
    long long res_;
public:
    Result(long long res) : res_(res) {}
    long long  get_res()
    {
        return res_;
    }
};

void func(long long a, long long b, unsigned k)
{
    if (k == 0) {
        throw Result(a + b);
    } else if (k > 0 && b == 1) {
        throw Result(a);
    } else {
        try {
            try {
                func(a, b - 1, k);
            } catch (Result res) {
                func(a, res.get_res(), k - 1);
            }
        } catch (Result res) {
            throw res;
        }
    }
    throw(Result(0));
}

int main()
{
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result res) {
            std::cout << res.get_res() << std::endl;
        }
    }
}