#include <iostream>

namespace Game {
    template<typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T row{}, col{};
        Coord(T r = T(), T c = T()) : row(r), col(c) {}
    };

    template<typename T>
    T dist(Coord<T> size, Coord<T> cell1, Coord<T> cell2)
    {
        T r1 = cell1.row, c1 = cell1.col, r2 = cell2.row, c2 = cell2.col;
        if (r2 < r1) {
            std::swap(r1, r2);
            std::swap(c1, c2);
        }
        T dist1, dist2;
        if (c1 % 2 == 0) {
            if (c2 < c1) {
                std::swap(c1, c2);
            }
            dist1 = c2 - c1;
            dist2 = (c2 - c1 + 1) / 2;
        } else {
            if (c2 < c1) {
                std::swap(c1, c2);
            }
            dist1 = c2 - c1;
            dist2 = (c2 - c1) / 2;
        }
        if (r2 - r1 > dist2) {
            return dist1 + (r2 - r1) - dist2;
        }
        return dist1;
    }
}
