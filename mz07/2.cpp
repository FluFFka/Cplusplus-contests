#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

class Rectangle : Figure
{
    double a_{}, b_{};
public:
    Rectangle(double a, double b) : a_(a), b_(b) {}
    static Rectangle *make(std::string str) {
        std::stringstream ss;
        ss << str;
        double a{}, b{};
        ss >> b >> a;
        Rectangle *t = new Rectangle(a, b);
        return t;
    }
    double get_square() const {
        return a_ * b_;
    }
};

class Square : Figure
{
    double a_{};
public:
    Square(double a) : a_(a) {}
    double get_square() const {
        return a_ * a_;
    }
    static Square *make(std::string str) {
        std::stringstream ss;
        ss << str;
        double a{};
        ss >> a;
        Square *t = new Square(a);
        return t;
    }
};

class Circle : Figure
{
    double r_{};
public:
    Circle(double r) : r_(r) {}
    double get_square() const {
        return r_ * r_ * M_PI;
    }
    static Circle *make(std::string str) {
        std::stringstream ss;
        ss << str;
        double r{};
        ss >> r;
        Circle *t = new Circle(r);
        return t;
    }
};