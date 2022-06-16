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
    set<ll> vals;
    ll x = 0, y = 0;
    function<void(ll, ll)> rec = [&](ll num, ll digs) {
        if (digs == 10) return;
        if (num) vals.insert(num);
        rec(num * 10 + x, digs + 1);
        rec(num * 10 + y, digs + 1);
    };
    for (x = 0; x <= 9; ++x)
        for (y = x + 1; y <= 9; ++y) rec(0, 0);
    vals.insert(1000000000);
    ll n;
    cin >> n;
    cout << distance(vals.begin(), vals.lower_bound(n + 1)) << '\n';
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