#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iterator>
#include <algorithm>

struct Height
{
    unsigned l{};
    int r{}, c{};
    Height(unsigned link, int raw, int col) : l(link), r(raw), c(col) { }
    friend bool operator < (const Height &left, const Height &right) {
        if (left.l < right.l) {
            return true;
        } else if (left.l == right.l){
            if (left.r > right.r) {
                return true;
            } else if (left.r == right.r) {
                if (left.c > right.c) {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

int main()
{
    std::vector<std::vector<unsigned>> field;
    std::string raw;
    while (std::getline(std::cin, raw), raw != "") {
        std::stringstream ss;
        ss << raw;
        unsigned el;
        field.push_back(std::vector<unsigned>());
        auto it = field.end() - 1;
        while (ss >> el) {
            (*it).push_back(el);
        }
    }
    std::set<Height> heights;
    int r{}, c{};
    for (auto &el1 : field) {
        for (auto &el2 : el1) {
            heights.insert(Height(el2, r, c));
            ++c;
        }
        c = 0;
        ++r;
    }
    std::vector<unsigned> eds;
    unsigned curr_edit{};
    while (std::cin >> curr_edit) {
        eds.push_back(curr_edit);
    }
    std::sort(eds.rbegin(), eds.rend());
    std::vector<std::pair<int, int>> dirs1 = {{1, 0}, {0, 1}, {-1, 0} , {0, -1}};
    std::vector<std::pair<int, int>> dirs2 = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    for (auto &edit : eds) {
        auto curr = *(heights.rbegin());
        int x_c = curr.r, y_c = curr.c;
        heights.erase(curr);
        if (edit < field[x_c][y_c]) {
            field[x_c][y_c] -= edit;
        } else {
            field[x_c][y_c] = 0;
        }
        heights.insert(Height(field[x_c][y_c], x_c, y_c));
        edit /= 2;
        if (edit > 0) {
            for (auto &dir : dirs1) {
                int dx = x_c + dir.first, dy = y_c + dir.second;
                if (dx >= 0 && size_t(dx) < field.size() && dy >= 0 && size_t(dy) < field[dx].size()) {
                    auto curr = *(heights.find(Height(field[dx][dy], dx, dy)));
                    heights.erase(curr);
                    if (edit < field[dx][dy]) {
                        field[dx][dy] -= edit;
                    } else {
                        field[dx][dy] = 0;
                    }
                    heights.insert(Height(field[dx][dy], dx, dy));
                }
            }
        }
        edit /= 2;
        if (edit > 0) {
            for (auto &dir : dirs2) {
                int dx = x_c + dir.first, dy = y_c + dir.second;
                if (dx >= 0 && size_t(dx) < field.size() && dy >= 0 && size_t(dy) < field[dx].size()) {
                    auto curr = *(heights.find(Height(field[dx][dy], dx, dy)));
                    heights.erase(curr);
                    if (edit < field[dx][dy]) {
                        field[dx][dy] -= edit;
                    } else {
                        field[dx][dy] = 0;
                    }
                    heights.insert(Height(field[dx][dy], dx, dy));
                }
                
            }
        }
    }
    for (auto &el1 : field) {
        for (auto &el2 : el1) {
            std::cout << el2 << " ";
        }
        std::cout << std::endl;
    }

}