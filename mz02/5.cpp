#include <string>

class BinaryNumber
{
    std::string s_ = "0";
public:
    BinaryNumber(const std::string &s) {
        if (s.size() != 0) {
            s_ = s;
        }
    }
    operator std::string() const {
        return s_;
    }
    const BinaryNumber &operator++() {
        //++num;
        bool take = 1;
        for (int i = s_.size() - 1; i >= 0; --i) {
            if (s_[i] == '0') {
                s_[i] = '1';
                take = 0;
                break;
            } else {
                s_[i] = '0';
            }
        }
        if (take) {
            s_ = "1" + s_;
        }
        return *this;
    }
};
