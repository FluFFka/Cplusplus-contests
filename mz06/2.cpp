#include <iostream>
#include <map>

enum { MOD = 4294967161} ;

int main()
{
    std::map<std::pair<unsigned, unsigned>, unsigned> matrix;
    unsigned r, c, v;
    while (std::cin >> r >> c >> v) {
        if (v == MOD) {
            break;
        }
        std::pair curr = {r, c};
        matrix[curr] = v % MOD;
    }
    while (std::cin >> r >> c >> v) {
        std::pair curr = {r, c};
        if (matrix.count(curr)) {
            matrix[curr] = ((unsigned long long)(matrix[curr]) + v) % MOD;
        } else {
            matrix[curr] = v % MOD;
        }
    }
    for (auto &[key, value]: matrix) {
        if (value != 0) {
            std::cout << key.first << " " << key.second << " " << value << std::endl;
        }
    }
}