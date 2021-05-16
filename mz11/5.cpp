#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::stack<std::string> cont;
    char c;
    while (std::cin >> c) {
        if (std::isspace(c)) {
            continue;
        }
        if (c == '+' || c == '-' || c == '/' || c == '*') {
            std::string first = cont.top();
            cont.pop();
            std::string second = cont.top();
            cont.pop();
            cont.push("(" + second + c + first + ")");
        } else {
            cont.push(std::string(1, c));
        }
    }
    std::cout << cont.top() << std::endl;
}