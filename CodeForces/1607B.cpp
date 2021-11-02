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

void Solution() {
    ll x, n;
    cin >> x >> n;
    ll ans = 0;
    ll m = (x % 2 + 2) % 2;
    if (m == 0) {
        if (n % 4 == 0) ans = x;
        if (n % 4 == 1) ans = x - n;
        if (n % 4 == 2) ans = x + 1;
        if (n % 4 == 3) ans = x + n + 1;
    } else {
        if (n % 4 == 0) ans = x;
        if (n % 4 == 1) ans = x + n;
        if (n % 4 == 2) ans = x - 1;
        if (n % 4 == 3) ans = x - n - 1;
    }
    cout << ans << '\n';
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}