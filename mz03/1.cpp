#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

namespace numbers
{
    class complex
    {
        double re_{}, im_{};
    public:
        complex(double real = 0, double image = 0) : re_{real}, im_{image} {}
        explicit complex(std::string s)
        {
            int num = 0;
            int res = 1;
            int ims = 1;
            double refl = 0;
            double imfl = 0;
            for (long unsigned int i = 0; i < s.size(); ++i) {
                if (num == 0) {
                    if (s[i] == '(') {
                        num = 1;
                    }
                } else if (num == 1) {
                    if (s[i] == ',') {
                        num = 3;
                    } else if (s[i] == '.') {
                        num = 2;
                    } else if (s[i] == '-') {
                        res = -1;
                    } else {
                        re_ *= 10;
                        re_ += s[i] - '0';
                    }
                } else if (num == 2) {
                    if (s[i] == ',') {
                        num = 3;
                    } else {
                        refl *= 10;
                        refl += s[i] - '0';
                    }
                } else if (num == 3) {
                    if (s[i] == ')') {
                        break;
                    } else if (s[i] == '.') {
                        num = 4;
                    } else if (s[i] == '-') {
                        ims = -1;
                    } else {
                        im_ *= 10;
                        im_ += s[i] - '0';
                    }
                } else {
                    if (s[i] == ')') {
                        break;
                    } else {
                        imfl *= 10;
                        imfl += s[i] - '0';
                    }
                }
            }
            while (refl >= 1) {
                refl /= 10;
            }
            re_ += refl;
            re_ *= res;
            while (imfl >= 1) {
                imfl /= 10;
            }
            im_ += imfl;
            im_ *= ims;
        }
        double re() const { return re_; }
        double im() const { return im_; }
        double abs2() const { return re_ * re_ + im_ * im_; }
        double abs() const { return sqrt(abs2()); }
        
        std::string to_string() const
        {
            std::stringstream ss;
            ss << std::setprecision(10) << "(" << re_ << "," << im_ << ")";
            std::string s;
            ss >> s;
            return s;
        }

        const complex & operator += (const complex &x)
        {
            re_ += x.re();
            im_ += x.im();
            return *this;
        }
        const complex & operator -= (const complex &x)
        {
            re_ -= x.re();
            im_ -= x.im();
            return *this;
        }
        const complex & operator *= (const complex &x) 
        {
            complex t = *this;
            re_ = t.re() * x.re() - t.im() * x.im();
            im_ = t.im() * x.re() + t.re() * x.im();
            return *this;
        }
        const complex & operator /= (const complex &x)
        {
            complex t = *this;
            re_ = (t.re() * x.re() + t.im() * x.im()) / x.abs2();
            im_ = (t.im() * x.re() - t.re() * x.im()) / x.abs2();
            return *this;
        }
        
        friend complex operator ~(const complex & x);
        friend complex operator -(const complex & x);

    };

    complex operator + (const complex & x, const complex & y)
    {
        complex result = complex(x.re(), x.im());
        return result += y;
    }
    complex operator - (const complex & x, const complex & y)
    {
        complex result = complex(x.re(), x.im());
        return result -= y;
    }
    complex operator * (const complex & x, const complex & y)
    {
        complex result = complex(x.re(), x.im());
        return result *= y;
    }
    complex operator / (const complex &x, const complex & y)
    {
        complex result = complex(x.re(), x.im());
        return result /= y;
    }
    complex operator ~(const complex & x)
    {
        return complex(x.re(), -x.im());
    }
    complex operator -(const complex & x)
    {
        return complex(-x.re(), -x.im());
    }


}