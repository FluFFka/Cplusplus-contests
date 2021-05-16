#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char *argv[])
{
    numbers::complex C(argv[1]);
    double R;
    int N;
    std::stringstream ss;
    ss << argv[3] << " " << argv[2];
    ss >> N >> R;
    std::vector<std::string> func;
    for (int i = 4; i < argc; ++i) {
        func.push_back(argv[i]);
    }
    numbers::complex integral(0, 0);
    double pi = acos(0) * 2;
    for (int i = 0; i < N; ++i) {
        double curr_angle = 2 * pi / N * i, next_angle = 2 * pi / N * (i + 1);
        numbers::complex curr(R * cos(curr_angle), R * sin(curr_angle));
        numbers::complex next(R * cos(next_angle), R * sin(next_angle));
        curr += C;
        next += C;
        integral += numbers::eval(func, curr) * (next - curr);
    }
    std::cout << integral.to_string() << std::endl;
}