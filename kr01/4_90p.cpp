#include <iostream>
#include <string>
#include <cassert>

class Figure
{
public:
    virtual ~Figure() {}
    virtual bool equals(Figure *) const = 0;
};

class Rectangle : public Figure
{
    double a_{}, b_{};
public:
    Rectangle(double a = 0, double b = 0) : a_(a), b_(b) {}
    bool equals(Figure *anoth) const {
        if (anoth == nullptr) {
            return false;
        }
        Rectangle canoth;
        try {
            canoth = dynamic_cast<Rectangle &>(*anoth);
        } catch(...) {
            return false;
        }
        if (canoth.a_ == a_ && canoth.b_ == b_) {
            return true;
        }
        return false;
    }
};

class Triangle : public Figure
{
    double a_{}, b_{}, c_{};
public:
    Triangle(double a = 0, double b = 0, double c = 0) : a_(a), b_(b), c_(c) {}
    bool equals(Figure *anoth) const {
        if (anoth == nullptr) {
            return false;
        }
        Triangle canoth;
        try {
            canoth = dynamic_cast<Triangle &>(*anoth);
        } catch(...) {
            return false;
        }
        if (canoth.a_ == a_ && canoth.b_ == b_ && canoth.c_ == c_) {
            return true;
        }
        return false;
    }
};
