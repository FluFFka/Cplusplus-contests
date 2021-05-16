#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>
#include <stdlib.h>

boost::gregorian::date parse(std::string s) {
    std::string y("0000"), m("00"), d("00");
    for (int i = 0; i < 4; ++i) {
        y[i] = s[i];
    } for (int j = 0; j < 2; ++j) {
        m[j] = s[j + 5];
    } for (int j = 0; j < 2; ++j) {
        d[j] = s[j + 8];
    }
    std::stringstream ss;
    ss << y << " " << m << " " << d;
    short unsigned int yy, mm, dd;
    ss >> dd >> mm >> yy;
    return boost::gregorian::date{dd, mm, yy};

}

int main()
{
    std::string s;
    std::cin >> s;
    long long res{};
    boost::gregorian::date dprev(parse(s));
    while (std::cin >> s) {
        boost::gregorian::date d(parse(s));
        res += abs((d - dprev).days());
        dprev = d;
    }
    std::cout << res << std::endl;
 

}