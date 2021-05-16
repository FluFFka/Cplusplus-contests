#include <iostream>
#include <vector>
#include <string>

bool is_gram(std::vector<std::vector<std::string> > gram)
{
    if (gram.size() == 0) {
        return false;
    }
    bool nonterm = false, exS = false;
    for (auto &el1 : gram) {
        for (auto &el2 : el1[0]) {
            if ('A' <= el2 && el2 <= 'Z') {
                nonterm = true;
                break;
            }
        }
        if (!nonterm) {
            return false;
        }
        nonterm = false;
        if (el1[0] == "S") {
            exS = true;
        }
    }
    return exS;
}

bool is_KS(std::vector<std::vector<std::string> > gram)
{
    for (auto &el : gram) {
        if (el[0].size() != 1) {
            return false;
        }
        if (!('A' <= el[0][0] && el[0][0] <= 'Z')) {
            return false;
        }
    }
    return true;
}

bool is_non_short(std::vector<std::vector<std::string> > gram)
{
    bool s_ = false;
    for (auto &el : gram) {
        if (el[0].size() > el[1].size()) {
            return false;
        }
        if (el[1] == "_" && el[0] != "S") {
            return false;
        }
        if (el[1] == "_" && el[0] == "S") {
            if (s_) {
                return false;
            }
            s_ = true;
        }
    }
    if (s_) {
        for (auto &el : gram) {
            for (auto &el2 : el[1]) {
                if (el2 == 'S') {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<std::string> > gram;
    std::string s1, s2;
    while (std::cin >> s1 && std::cin >> s2) {
        gram.push_back(std::vector<std::string>{s1, s2});
    }
    if (!is_gram(gram)) {
        std::cout << -1;
    } else if (is_KS(gram)) {
        std::cout << 2;
        if (is_non_short(gram)) {
            std::cout << 3;
        }
    } else {
        std::cout << 10;
    }
    std::cout << std::endl;
    
    return 0;
}