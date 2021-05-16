#include <iostream>
#include <string>

class PrintString
{
    std::string s_;
public:
    PrintString(std::string s) : s_(s) {}
    ~PrintString()
    {
        std::cout << s_ << std::endl;
    }
};

void solve()
{
    std::string t;
    if (std::cin >> t) {
        PrintString s(t);
        try {
            solve();
        } catch (...) {
        }
    }
    throw -1;
}

int main()
{
    try {
        solve();
    } catch (...) {

    }
}