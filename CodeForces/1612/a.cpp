#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

ll dist(ll x, ll y, ll x1, ll y1) {
    return abs(x - x1) + abs(y - y1);
}

void Solution() {
    ll x, y;
    cin >> x >> y;
    for (ll i = 0; i <= 50; ++i) {
        for (ll j = 0; j <= 50; ++j) {
            if (dist(0, 0, i, j) == dist(i, j, x, y)) {
                return void(cout << i << ' ' << j << '\n');
            }
        }
    }
    cout << "-1 -1\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}