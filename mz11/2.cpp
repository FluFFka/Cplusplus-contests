#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

int main()
{
    std::string s1, s2;
    std::vector<std::vector<std::string> > gram;
    while (std::cin >> s1 >> s2) {
        gram.push_back({s1, s2});
    }
    std::map<char, std::vector<char>> reach;
    for (auto &el : gram) {
        for (auto &f : el[0]) {
            for (auto &s : el[1]) {
                reach[f].push_back(s);
            }
        }
    }
    std::map<char, int> d;
    std::queue<char> q;
    q.push('S');
    d['S'] = 1;
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        for (auto &el : reach[curr]) {
            if (d[el] == 0) {
                d[el] = 1;
                q.push(el);
            }
        }
    }
    for (auto &el : gram) {
        bool found = false;
        for (auto &f : el[0]) {
            if (!d[f]) {
                found = true;
                break;
            }
        }
        for (auto &f : el[1]) {
            if (!d[f]) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << el[0] << " " << el[1] << std::endl;
        }
    }
}