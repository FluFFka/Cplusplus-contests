#include <iostream>
#include <vector>
#include <string>

bool is_non_short(std::vector<std::vector<std::string> > gram)
{
    bool s_ = false;
    for (auto &el : gram) {
        if (el[0] == "_") {
            return false;
        }
        if (el[1] == "_") {
            if (el[0] == "S") {
                s_ = true;
            } else if (el[0] != "_") {
                return false;
            }
        }
        if (el[0].size() > el[1].size()) {
            return false;
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

bool is_left(std::vector<std::vector<std::string> > gram)
{
    for (auto &el : gram) {
        if (el[0].size() > 1) {
            return false;
        }
        for (auto it = el[1].begin() + 1; it != el[1].end(); ++it) {
            if ('A' <= *it && *it <= 'Z') {
                return false;
            }
        }
    }
    return true;
}

bool is_right(std::vector<std::vector<std::string> > gram)
{
    for (auto &el : gram) {
        if (el[0].size() > 1) {
            return false;
        }
        for (auto it = el[1].begin(); it != el[1].end() - 1; ++it) {
            if ('A' <= *it && *it <= 'Z') {
                return false;
            }
        }
    }
    return true;
}

bool is_right_auto(std::vector<std::vector<std::string> > gram)
{
    bool s_ = false;
    for (auto &el : gram) {
        if (el[1].size() == 2) {
            if (!('A' <= el[1][0] && el[1][0] <= 'Z') && ('A' <= el[1][1] && el[1][1] <= 'Z')) {
            } else {
                return false;
            }
        } else if (el[1].size() == 1) {
            if (!('A' <= el[1][0] && el[1][0] <= 'Z') && el[1][0] != '_'){
            } else if (el[0][0] == 'S') {
                s_ = true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if (s_) {
        for (auto &el : gram) {
            for (auto &el1 : el[1]) {
                if (el1 == 'S') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool is_left_auto(std::vector<std::vector<std::string> > gram)
{
    bool s_ = false;
    for (auto &el : gram) {
        if (el[1].size() == 2) {
            if (!('A' <= el[1][1] && el[1][1] <= 'Z') && ('A' <= el[1][0] && el[1][0] <= 'Z')) {
            } else {
                return false;
            }
        } else if (el[1].size() == 1) {
            if (!('A' <= el[1][0] && el[1][0] <= 'Z') && el[1][0] != '_'){
            } else if (el[0][0] == 'S') {
                s_ = true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    if (s_) {
        int cntS = 0;
        for (auto &el : gram) {
            if (el[0][0] == 'S') {
                cntS++;
            }
            for (auto &el1 : el[1]) {
                if (el1 == 'S') {
                    return false;
                }
            }
        }
        if (cntS > 2) {
            return false;
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
    bool isl = is_left(gram), isr = is_right(gram);
    if (!is_non_short(gram) && !isl && !isr) {
        std::cout << 2 << std::endl;
        return 0;
    }
    if (!isl && !isr) {
        std::cout << 21 << std::endl;
        return 0;
    }
    if (isl) {
        std::cout << 31;
        if (is_left_auto(gram)) {
            std::cout << 1;
        }
        std::cout << std::endl;
    } else {
        std::cout << 32;
        if (is_right_auto(gram)) {
            std::cout << 1;
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}