#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    auto ask = [&](const string &s) -> pair<int, int> {
        cout << s << endl;
        int a, b;
        cin >> a >> b;
        if (a == 4 && b == 0) exit(0);
        return {a, b};
    };
    string present = "";  // check each digit as all unique
    for (int i = 0; i <= 9; ++i) {
        auto t = ask(string(4, char(i + '0')));
        if (t.first + t.second) present += char(i + '0');
    }
    do {
        ask(present);
    } while (next_permutation(all(present)));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}