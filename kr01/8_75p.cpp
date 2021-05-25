#include <string>

std::string gen_power(uint32_t power)
{
    if (power == 0) {
        return "1";
    }
    std::string res = "";
    for (long long i = 0; i < power; ++i) {
        res.push_back('x');
    }
    for (uint32_t i = 0; i < power - 1; ++i) {
        res.push_back('*');
    }
    return res;
}
