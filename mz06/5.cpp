#include <iostream>
#include <vector>
#include <string>
#include <map>

enum {
    FRONT = 0,
    UP,
    BACK,
    DOWN,
    LEFT,
    RIGHT
};

class Direction
{
private:
    int x_{}, y_{};
public:
    Direction(int x, int y) : x_(x), y_(y) {
        if (x + y != 1 && x + y != -1) {
            std::cout << "wrong direction" << std::endl;
        }
    }
    void right() {
        if (x_ == 0 && y_ == 1) {
            x_ = -1;
            y_ = 0;
        } else if (x_ == 1 && y_ == 0) {
            x_ = 0;
            y_ = 1;
        } else if (x_ == 0 && y_ == -1) {
            x_ = 1;
            y_ = 0;
        } else {
            x_ = 0;
            y_ = -1;
        }
    }
    void left() {
        if (x_ == 0 && y_ == -1) {
            x_ = -1;
            y_ = 0;
        } else if (x_ == -1 && y_ == 0) {
            x_ = 0;
            y_ = 1;
        } else if (x_ == 0 && y_ == 1) {
            x_ = 1;
            y_ = 0;
        } else {
            x_ = 0;
            y_ = -1;
        }
    }
    int x() const {
        return x_;
    }
    int y() const {
        return y_;
    }
    void set(int x, int y) {
        x_ = x;
        y_ = y;
        if (x + y != 1 && x + y != -1) {
            std::cout << "wrong direction" << std::endl;
        }

    }
};

class Cube
{
private:
    int x{1}, y{1}, face{FRONT};
    Direction d_{1, 0};
    std::map<int, std::vector<std::vector<int> > > cube_;
public:
    Cube() {
        for (int i = 0; i < 6; ++i) {
            cube_[i] = std::vector<std::vector<int> >(3, std::vector<int>(3, 0));
        }
        cube_[FRONT][1][1] = 1;
    }
    void left() {
        d_.left();
    }
    void right() {
        d_.right();
    }
    void step() {
        switch (face) {
            case FRONT:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = 0;
                        face = UP;
                    } else if (x == -1) {
                        x = 2;
                        face = DOWN; 
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = 2;
                        x = 2 - x;
                        d_.set(0, -1);
                        face = RIGHT;
                    } else if (y == -1) {
                        y = 0;
                        x = 2 - x;
                        d_.set(0, 1);
                        face = LEFT;
                    }
                }
                break;
            case UP:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = 0;
                        face = BACK;
                    } else if (x == -1) {
                        x = 2;
                        face = FRONT; 
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = 2 - x;
                        x = 0;
                        d_.set(1, 0);
                        face = RIGHT;
                    } else if (y == -1) {
                        y = x;
                        x = 0;
                        d_.set(1, 0);
                        face = LEFT;
                    }
                }
                break;
            case BACK:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = 0;
                        face = DOWN;
                    } else if (x == -1) {
                        x = 2;
                        face = UP; 
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = 0;
                        face = RIGHT;
                    } else if (y == -1) {
                        y = 2;
                        face = LEFT;
                    }
                }
                break;
            case DOWN:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = 0;
                        face = FRONT;
                    } else if (x == -1) {
                        x = 2;
                        face = BACK;
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = x;
                        x = 2;
                        d_.set(-1, 0);
                        face = RIGHT;
                    } else if (y == -1) {
                        y = 2 - x;
                        x = 2;
                        d_.set(-1, 0);
                        face = LEFT;
                    }
                }
                break;
            case RIGHT:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = y;
                        y = 2;
                        d_.set(0, -1);
                        face = DOWN;
                    } else if (x == -1) {
                        x = 2 - y;
                        y = 2;
                        d_.set(0, -1);
                        face = UP;
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = 2;
                        x = 2 - x;
                        d_.set(0, -1);
                        face = FRONT;
                    } else if (y == -1) {
                        y = 2;
                        face = BACK;
                    }
                }
                break;
            case LEFT:
                if (d_.x() != 0) {
                    x += d_.x();
                    if (x == 3) {
                        x = 2 - y;
                        y = 0;
                        d_.set(0, 1);
                        face = DOWN;
                    } else if (x == -1) {
                        x = y;
                        y = 0;
                        d_.set(0, 1);
                        face = UP;
                    }
                } else {
                    y += d_.y();
                    if (y == 3) {
                        y = 0;
                        face = BACK;
                    } else if (y == -1) {
                        y = 0;
                        x = 2 - x;
                        d_.set(0, 1);
                        face = FRONT;
                    }
                }
                break;
        }
        cube_[face][x][y] = 1;
    }
    void print() {
        for (int i = 2; i >= 0; --i) {
            std::cout << "      ";
            for (int j = 0; j < 3 ; ++j) {
                std::cout << cube_[DOWN][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 2; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << cube_[LEFT][i][j] << " ";
            }
            for (int j = 0; j < 3; ++j) {
                std::cout << cube_[BACK][i][j] << " ";
            }
            for (int j = 0; j < 3; ++j) {
                std::cout << cube_[RIGHT][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 2; i >= 0; --i) {
            std::cout << "      ";
            for (int j = 0; j < 3 ; ++j) {
                std::cout << cube_[UP][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 2; i >= 0; --i) {
            std::cout << "      ";
            for (int j = 0; j < 3 ; ++j) {
                std::cout << cube_[FRONT][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    int result() {
        int res = 0;
        res += cube_[BACK][1][1];
        res += std::max(cube_[BACK][0][0], std::max(cube_[UP][2][0], cube_[LEFT][0][2]));
        res += std::max(cube_[BACK][0][2], std::max(cube_[UP][2][2], cube_[RIGHT][0][0]));
        res += std::max(cube_[BACK][2][0], std::max(cube_[DOWN][0][0], cube_[LEFT][2][2]));
        res += std::max(cube_[BACK][2][2], std::max(cube_[DOWN][0][2], cube_[RIGHT][2][0]));
        res += std::max(cube_[BACK][0][1], cube_[UP][2][1]);
        res += std::max(cube_[BACK][1][0], cube_[LEFT][1][2]);
        res += std::max(cube_[BACK][1][2], cube_[RIGHT][1][0]);
        res += std::max(cube_[BACK][2][1], cube_[DOWN][0][1]);

        res += cube_[FRONT][1][1];
        res += std::max(cube_[FRONT][0][0], std::max(cube_[DOWN][2][0], cube_[LEFT][2][0]));
        res += std::max(cube_[FRONT][0][2], std::max(cube_[DOWN][2][2], cube_[RIGHT][2][2]));
        res += std::max(cube_[FRONT][2][0], std::max(cube_[UP][0][0], cube_[LEFT][0][0]));
        res += std::max(cube_[FRONT][2][2], std::max(cube_[UP][0][2], cube_[RIGHT][0][2]));
        res += std::max(cube_[FRONT][0][1], cube_[DOWN][2][1]);
        res += std::max(cube_[FRONT][1][0], cube_[LEFT][1][0]);
        res += std::max(cube_[FRONT][1][2], cube_[RIGHT][1][2]);
        res += std::max(cube_[FRONT][2][1], cube_[UP][0][1]);
        
        res += cube_[UP][1][1];
        res += cube_[RIGHT][1][1];
        res += cube_[DOWN][1][1];
        res += cube_[LEFT][1][1];

        res += std::max(cube_[UP][1][2], cube_[RIGHT][0][1]);
        res += std::max(cube_[RIGHT][2][1], cube_[DOWN][1][2]);
        res += std::max(cube_[DOWN][1][0], cube_[LEFT][2][1]);
        res += std::max(cube_[LEFT][0][1], cube_[UP][1][0]);
        return res;
    }
};

int main()
{
    Cube c;
    std::string commands;
    std::cin >> commands;
    for (auto com : commands) {
        if (com == 'L') {
            c.left();
        } else if (com == 'R') {
            c.right();
        } else if (com == 'F') {
            c.step();
        } else {
            break;
        }
    }
    std::cout << c.result() << std::endl;
}