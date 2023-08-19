#include <iostream>
#include <thread>

int res1 = 0;

void calc(int lo, int hi, int& res) {
    for (int i = lo; i <= hi; ++i) {
        res ^= i;
    }
}

// main thread
int main() {
    // seperate thread
    std::thread t(calc, 100, 5e8, std::ref(res1));
    int res2 = 0;
    calc(5e8 + 1, 1e9, res2);

    // main thread waits for t thread to finish
    t.join();

    int res = res1 ^ res2;

    int resReal = 0;
    calc(100, 1e9, resReal);
    std::cout << res << ' ' << resReal << '\n';
}