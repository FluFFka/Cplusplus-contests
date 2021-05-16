#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <array>

namespace Equations
{
    template<typename T>
    bool is_zero(std::complex<T> a) {
        return std::norm(a) < 32 * std::numeric_limits<T>::epsilon();
    }
    template<typename T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> v)
    {
        std::pair<bool, std::vector<std::complex<T>>> res;
        
        std::complex<T> a = v[2], b = v[1], c = v[0];
        if (is_zero(a)) {
            if (is_zero(b)) {
                if (is_zero(c)) {
                    res = {false, std::vector<std::complex<T>>()};
                } else {
                    res = {true, std::vector<std::complex<T>>()};
                }
            } else {
                res = {true, std::vector<std::complex<T>>()};
                std::complex<T> z = std::complex<T>(-1) * c / b;
                res.second.push_back(z);
            }
        } else {
            std::complex<T> z1 = (std::complex<T>(-1) * b + 
                    sqrt(b * b - std::complex<T>(4) * a * c)) / (std::complex<T>(2) * a);
            std::complex<T> z2 = (std::complex<T>(-1) * b - 
                    sqrt(b * b - std::complex<T>(4) * a * c)) / (std::complex<T>(2) * a);
            res.first = true;
            res.second.push_back(z1);
            res.second.push_back(z2);
        }
        return res;
    }
};