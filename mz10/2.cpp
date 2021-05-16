#include <iostream>
#include <string>

int main()
{
    char buf;
    int n1{}, n0{}, chn1{}, chn0{};
    int st{};
    bool skip = false, skip2 = true;
    while ((buf = getchar()) != EOF) {
        if (std::isspace(buf)) {
            if (skip || skip2) {
                n1 = 0;
                n0 = 0;
                chn0 = 0;
                chn1 = 0;
                st = 0;
                skip = false;
                skip2 = true;
                continue;
            }
            if (n1 != 0 && n0 != 0 && st == 1) {
                std::cout << "1" << std::endl;
            } else if (n1 == 0 || n0 == 0 || chn0 != n0 || chn1 != n1) {
                std::cout << "0" << std::endl;
            } else {
                std::cout << "1" << std::endl;
            }
            skip2 = true;
            n1 = 0;
            n0 = 0;
            chn0 = 0;
            chn1 = 0;
            st = 0;
            continue;
        }
        skip2 = false;
        if (skip) {
            continue;
        }
        if (st == 0) {
            if (buf == '0') {
                n0++;
            } else {
                st = 1;
            }
        }
        if (st == 1) {
            if (buf == '1') {
                n1++;
            } else {
                st = 2;
            }
        }
        if (st == 2) {
            if (buf == '0') {
                chn0++;
            } else {
                st = 3;
            }
        }
        if (st == 3) {
            if (buf == '1') {
                chn1++;
            } else if (buf != '0') {
                std::cout << "0" << std::endl;
                skip = true;
            } else { //buf == '0'
                if (n0 == 0 || n1 == 0 || chn0 != n0 || chn1 != n1) {
                    std::cout << "0" << std::endl;
                    skip = true;
                } else {
                    chn1 = 0;
                    chn0 = 1;
                    st = 2;
                }
            }
        }
    }
    if (skip || skip2) {
        n1 = 0;
        n0 = 0;
        chn0 = 0;
        chn1 = 0;
        st = 0;
        skip = false;
        skip2 = true;
        return 0;
    }
    if (n1 != 0 && n0 != 0 && st == 1) {
        std::cout << "1" << std::endl;
    } else if (n1 == 0 || n0 == 0 || chn0 != n0 || chn1 != n1) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }
    skip2 = true;
    n1 = 0;
    n0 = 0;
    chn0 = 0;
    chn1 = 0;
    st = 0;

}