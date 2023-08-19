#include <iostream>

int calc(int lo, int hi) {
    int res = 0;
    for (int i = lo; i <= hi; ++i) {
        res ^= i;
    }
    return res;
}

int main() {
    std::thread t(calc, 5, 10);
    std::cout << calc(5, 10) << '\n';
}