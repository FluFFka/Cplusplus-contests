#include <iostream>
#include <string>
int main()
{
    std::string ans = "";
    int curr{};
    char c{};
    bool nuls{}, num{};
    while ((curr = std::cin.get()) != EOF) {
        c = curr;
        if (c == '0') {
            if (!num) {
                nuls = 1;
            } else {
                ans += '0';
                nuls = 0;
            }
        } else if ('0' < c && c <= '9') {
            nuls = 0;
            num = 1;
            ans += c;
        } else {
            num = 0;
            if (nuls) {
                ans += '0';
                nuls = 0;
            }
            ans += c;
        }
    }
    if (nuls) {
        ans += "0";
    }
    std::cout << ans;
}