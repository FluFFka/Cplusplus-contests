#include <iostream>

class S
{
    int a_{};
    bool valid_{true};
    bool valid2_{false};
public:
    S()
    {
        if (std::cin >> a_) {
        } else {
            valid_ = false;
            valid2_ = true;
        } 
    }
    S(S&& v) {
        if (std::cin >> a_) {
        } else {
            valid_ = false;
        }
        a_ += v.get_a();
    }
    ~S()
    {
        if (!valid2_ && !valid_) {
            std::cout << a_ << std::endl;
        }
    }
    int get_a()
    {
        return a_;
    }
    operator bool() {
        return valid_;
    }
};