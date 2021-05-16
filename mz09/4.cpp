#include <iostream>

int main()
{
    int count;
    std::cin >> count;

    Holder *h = new Holder[count];
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            h[j].swap(h[j + 1]);
        }
    }
    delete[] h;
}