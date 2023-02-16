#include <bits/stdc++.h>
using namespace std;

void print() {
    cout << '\n';
}

template <typename T, typename... Types>
void print(T a, Types... b) {
    cout << a << ' ';
    print(b...);
}

int main() {
    print(1, 2, 3, 4, "Hello world", "test");
}
