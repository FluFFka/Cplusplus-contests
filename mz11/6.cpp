#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::map<int, std::string> > automat;
    automat["H"]['0'] = "A";
    automat["H"]['1'] = "AB";
    automat["A"]['0'] = "A";
    automat["A"]['1'] = "AB";
    automat["AB"]['0'] = "AC";
    automat["AB"]['1'] = "ABC";
    automat["AC"]['0'] = "AS";
    automat["AC"]['1'] = "ABS";
    automat["ABC"]['0'] = "ACS";
    automat["ABC"]['1'] = "ABCS";
    automat["AS"]['0'] = "A";
    automat["AS"]['1'] = "AB";
    automat["AS"][-1] = "y";
    automat["ABS"]['0'] = "AC";
    automat["ABS"]['1'] = "ABC";
    automat["ABS"][-1] = "y";
    automat["ACS"]['0'] = "AS";
    automat["ACS"]['1'] = "ABS";
    automat["ACS"][-1] = "y";
    automat["ABCS"]['0'] = "ACS";
    automat["ABCS"]['1'] = "ABCS";
    automat["ABCS"][-1] = "y";

    
    std::string str;
    while (std::cin >> str) {
        std::string cur = "H";
        int num = 0;
        bool printed = false;
        for (auto it = str.begin(); it != str.end(); ++it, ++num) {
            if (automat[cur].find(*it) == automat[cur].end()) {
                std::cout << 0 << std::endl;
                printed = true;
                break;
            } else {
                cur = automat[cur][*it];
            }
        }
        if (!printed) {
            if (automat[cur][-1] != "y") {
                std::cout << 0 << std::endl;
            } else {
                std::cout << 1 << std::endl;
            }
        }
    }
}