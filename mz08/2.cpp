#include <iostream>

template<typename T>
class Coord
{
public:
    typedef T value_type;
    T row{}, col{};
    Coord(T r = T(), T c = T()) : row(r), col(c) {}
};

template<typename T>
int dist(Coord<T> size, Coord<T> cell1, Coord<T> cell2)
{
    T m = size.row, n = size.row;
    T r1 = cell1.row, c1 = cell1.col, r2 = cell2.row, c2 = cell2.col;
    if (r1 < r2) {
        std::swap(r1, r2);
    }
    if (c1 < c2) {
        std::swap(c1, c2);
    }
    return std::max(std::min(r1 - r2, m - r1 + r2), std::min(c1 - c2, n - c1 + c2));
}
