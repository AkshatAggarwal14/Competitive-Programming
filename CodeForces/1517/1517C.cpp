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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> vv(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j <= i; ++j)
            vv[i][j] = (j == i ? a[i] : 0);
    for (ll i = 0; i < n; ++i) {
        ll cnt = a[i] - 1;
        ll sx = i, sy = i;
        while (cnt--) {
            if (sy - 1 >= 0 && vv[sx][sy - 1] == 0)
                sy--;  // go left is possible, else down until cnt == 0
            else if (sx + 1 < n && vv[sx + 1][sy] == 0)
                sx++;
            vv[sx][sy] = a[i];
        }
    }
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j <= i; ++j)
            cout << vv[i][j] << " \n"[j == i];
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
// #ifdef LOCAL
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}