#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Sum
{
    double res{};
    void operator () (double curr) {
        res += curr;
    }
};

int main()
{
    std::cout << std::setprecision(10) << std::fixed;
    std::vector<double> exp;
    double curr;
    while (std::cin >> curr) {
        exp.push_back(curr);
    }
    int bord = exp.size() / 10;
    std::sort(exp.begin() + bord, exp.end() - bord);
    bord += (exp.size() - 2 * bord) / 10;
    Sum s = for_each(exp.begin() + bord, exp.end() - bord, Sum());
    std::cout << s.res / (exp.size() - 2 * bord) << std::endl;
}