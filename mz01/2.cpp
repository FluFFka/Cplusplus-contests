#include <iostream>

class A
{
    int num{}, check{};
public:
    A() {
        check = 0;
        std::cin >> num;
    }
    A(const A &a) {
        check = 1;
        std::cin >> num;
        num += a.get();
    }
    ~A() {
        if (check) {
            std::cout << num << std::endl;
        }
    }
    int get() const {
        return num;
    }
};