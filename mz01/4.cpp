#include <iostream>
#include <iomanip>
#include <cmath>

class Aver
{
    double sum{};
    double sum2{};
    int num{};
public:
    Aver(double a) {
        sum = a;
        sum2 = a * a;
        num = 1;
    }
    Aver(const Aver &a, double temp) {
        sum = a.get_sum() + temp;
        sum2 = a.get_sum2() + temp * temp;
        num = a.get_num() + 1;
    }
    int get_num() const {
        return num;
    }
    double get_sum() const {
        return sum;
    }
    double get_sum2() const {
        return sum2;
    }
    double get_av() const {
        return sum / num;
    }
    double get_quad() const {
        return sqrt(sum2 / num - (sum / num * sum / num));
    }
};

int main()
{
    double temp{};
    std::cin >> temp;
    Aver prev(temp);
    while (std::cin >> temp) {
        Aver next(prev, temp);
        prev = next;
    }
    std::cout << std::fixed << std::setprecision(10) << prev.get_av() << std::endl << prev.get_quad() << std::endl;
}