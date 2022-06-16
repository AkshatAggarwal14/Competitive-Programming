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

void Solution() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll weeks = min({a / 3, b / 2, c / 2}), mx = -1;
    vector<ll> days = {1, 2, 3, 1, 3, 2, 1};
    for (ll start = 0; start < 7; ++start) {
        ll a_left = a - 3 * weeks, b_left = b - 2 * weeks, c_left = c - 2 * weeks;
        ll ctr = 0;
        for (ll i = start; i < 14 + start; ++i) {
            if (days[i % 7] == 1) --a_left;
            if (days[i % 7] == 2) --b_left;
            if (days[i % 7] == 3) --c_left;
            if (a_left >= 0 && b_left >= 0 && c_left >= 0) ctr++;
        }
        amax(mx, ctr);
    }
    cout << weeks * 7 + mx << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}